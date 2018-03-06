struct simulated_network::node_info {
    node_delegate *delegate;
    fc::future<void> message_sender_task_done;
    std::queue<message> messages_to_deliver;

    node_info(node_delegate *delegate) : delegate(delegate) {
    }
};

simulated_network::~simulated_network() {
    for (node_info *network_node_info : network_nodes) {
        network_node_info->message_sender_task_done.cancel_and_wait("~simulated_network()");
        delete network_node_info;
    }
}

void simulated_network::message_sender(node_info *destination_node) {
    while (!destination_node->messages_to_deliver.empty()) {
        try {
            const message &message_to_deliver = destination_node->messages_to_deliver.front();
            if (message_to_deliver.msg_type == trx_message_type) {
                destination_node->delegate->handle_transaction(message_to_deliver.as<trx_message>());
            } else if (message_to_deliver.msg_type ==
                       block_message_type) {
                std::vector<fc::uint160_t> contained_transaction_message_ids;
                destination_node->delegate->handle_block(message_to_deliver.as<block_message>(), false, contained_transaction_message_ids);
            } else {
                destination_node->delegate->handle_message(message_to_deliver);
            }
        }
        catch (const fc::exception &e) {
            elog("${r}", ("r", e));
        }
        destination_node->messages_to_deliver.pop();
    }
}

void simulated_network::broadcast(const message &item_to_broadcast) {
    for (node_info *network_node_info : network_nodes) {
        network_node_info->messages_to_deliver.emplace(item_to_broadcast);
        if (!network_node_info->message_sender_task_done.valid() ||
            network_node_info->message_sender_task_done.ready()) {
            network_node_info->message_sender_task_done = fc::async([=]() { message_sender(network_node_info); }, "simulated_network_sender");
        }
    }
}

void simulated_network::add_node_delegate(node_delegate *node_delegate_to_add) {
    network_nodes.push_back(new node_info(node_delegate_to_add));
}