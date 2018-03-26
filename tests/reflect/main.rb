Tabs_count = 3
Spaces_in_tab = 4
Structures = {}

class Structure_info
  @name = ""
  @fields = []
  @parents = []
  @path = ""
  @macro = ""
  @inherited_fields = []
  attr_accessor :name, :fields, :parents, :path, :macro, :inherited_fields

  def to_s
    return [@macro, @name, @fields.to_s, @parents, @path, @inherited_fields.to_s].to_s
  end

  def cut_path
    p = @path.index("golos")
    @path = @path[p..-1]
  end

  def fill_inherited_fields(xxx = "start > ")
    if @macro != "FC_REFLECT_DERIVED"
      return @fields
    else
      res = []

      for i in 0...@parents.size
        c = Structures[ @parents[i] ]
        if c == nil
          c = Structures[Api_typedefs[@parents[i]]]
          return
        end
        
        v = c.fill_inherited_fields(@name)
        v.each {|x| res << x}
      end
      @inherited_fields = res
      return @inherited_fields
    end
  end


  def get_cpp_test_case 
    tab = " " * 4
    padding = 1
    tmp = @name.split("::")
    test_name = ""
    tmp.each { |x| test_name += x + "_"}
    test_name = test_name[0...-1]

    data = tab * padding + "BOOST_AUTO_TEST_CASE(#{test_name}) {\n"
    padding += 1

    data += tab * padding + "try {\n"
    padding += 1

    data += tab * padding + "#{@name} v1, v2;\n"

    data += "\n"
    len = @fields.size
    for i in 0...len
      data += tab * padding + "set_random_value(v1." + @fields[i] + ");\n"
    end
    data += "\n"

    data += tab * padding + "auto data = fc::raw::pack(v1);\n" +
            tab * padding + "std::fstream stream_ex, stream_results;\n" + 
            tab * padding + "stream_ex.exceptions(std::fstream::failbit | std::fstream::badbit);\n" + 
            tab * padding + "fc::path file(\"logs\");\n" + 
            tab * padding + "stream_ex.open(file.generic_string().c_str(), std::ios::out | std::ios::binary);\n" + 
            tab * padding + "stream_ex.write(data.data(), data.size());\n" + 
            tab * padding + "stream_ex.close();\n" + 
            tab * padding + "\n" + 
            tab * padding + "fc::path resutl_file(REFLECT_TESTS_OUTPUT_FILE);\n" + 
            tab * padding + "stream_results.open(resutl_file.generic_string().c_str(), std::ios::out | std::ios::binary);\n" + 
            tab * padding + "stream_results.write(data.data(), data.size());\n" + 
            tab * padding + "stream_results.close();\n" +
            tab * padding + "\n" + 
            tab * padding + "stream_ex.open(file.generic_string().c_str(), std::ios::in | std::ios::binary);\n" + 
            tab * padding + "fc::raw::unpack(stream_ex, v2);\n" + 
            tab * padding + "stream_ex.close();\n"
    data += "\n"

    padding -= 1
    data += tab * padding + "}\n" + 
            tab * padding + "FC_LOG_AND_RETHROW()\n"
    padding -= 1
    data += tab* padding + "}\n"
    data += "\n"
    
    return data
  end

end


def get_reflections_in_file(path, macro)
  f = File.open(path, "r") 
  data = ""
  f.each_line do |line|
    data += line
  end

  res = []
  input = data
  while true
    tmp = find_fc_reflect(input, macro)
    if tmp == nil 
      break
    else
      res << tmp[0]
      input = input[tmp[1]...input.size]
    end
  end

  for i in 0...res.size
    # puts res[i]
    obj = parse_reflected_struct(res[i], path)
    if obj != nil
      Structures[obj.name] = obj
      obj.cut_path
    end
  end

  return res
end


def find_fc_reflect(data, macro)
  reflect_idx = data.index(macro)

  return nil if data.index(macro).nil?

  first_parenthesis_idx = -1
  last_parenthesis_idx = -1

  for i in reflect_idx...data.size 
    if data[i] == "("
      first_parenthesis_idx = i
      break
    end
  end
  counter = 0
  correct = false

  for i in (first_parenthesis_idx) ... data.size
    correct = true if data == ','
    counter += 1 if data[i] == '('
    counter -= 1 if data[i] == ')'
    if counter == 0 
      last_parenthesis_idx = i
      break
    end
  end

  return nil if correct == nil

  return [data[reflect_idx..last_parenthesis_idx], last_parenthesis_idx]
end

def travel(path) 

  Dir.foreach(path) do |item|
    next if item == '.' or item == '..'
    np = path + "/" + item

    if File.directory?(np)
      travel(np)
    else
      next if item == "reflect.hpp"
      s = File.basename(np).split('.')[-1]

      if s == "h" || s == "hpp" || s == "cpp"
        f = File.open(np, "r") 
        data = ""
        f.each_line do |line|
          data += line
        end
        macro = "FC_REFLECT"
        get_reflections_in_file(np, macro) if data.index(macro).nil? == false
      end
    end
  end
   
end

def parse_reflected_struct(data, path)
  reflect_macro = data.split("(")[0]

  obj = Structure_info.new
  obj.path = path
  data = data.gsub(/\s+/, ' ').strip


  data = data[data.index("(")...data.size]

  if reflect_macro == "FC_REFLECT"
    parts = data.split(",")
    return nil if parts.size == 1
    name = parts[0]
    name = name[1..-1]
    # cutting trailing spaces....
    for i in  0...name.size
      if name[i] != ' '
        len = name.size
        name = name[i...len]
        break
      end
    end
    name = cut_one_word (name)
    name = name[0]

    str = parts[1]
    fields = []
    while true
      res = cut_one_word(str)
      if res == nil
        break
      end
      fields << res[0]
      str = res[1]
    end
    obj.name = name
    obj.fields = fields
    obj.macro = "FC_REFLECT"
    return obj
  elsif reflect_macro == "FC_REFLECT_DERIVED"
    parts = data.split(",")
    return nil if parts.size == 1

    name = parts[0]
    name = cut_one_word (name)
    name = name[0]

    par_s = parts[1]
    parents = []
    loop do
      tmp = cut_one_word(par_s)
      break if tmp == nil
      parents << tmp[0]
      par_s = tmp[1]
    end

    field_s = parts[2]
    fields = []
    loop do
      tmp = cut_one_word(field_s)
      break if tmp == nil
      fields << tmp[0]
      field_s = tmp[1]
    end
    obj.name = name
    obj.fields = fields
    obj.parents = parents
    obj.macro = "FC_REFLECT_DERIVED"

    return obj
  elsif reflect_macro == "FC_REFLECT_ENUM"
    parts = data.split(",")
    return nil if parts.size == 1
    name = parts[0]
    name = name[1..-1]
    # cutting trailing spaces....
    for i in  0...name.size
      if name[i] != ' '
        len = name.size
        name = name[i...len]
        break
      end
    end
    name = cut_one_word (name)
    name = name[0]

    field_s = parts[1]
    fields = []
    loop do
      tmp = cut_one_word(field_s)
      break if tmp == nil
      fields << tmp[0]
      field_s = tmp[1]
    end

    obj.name = name
    obj.macro = "FC_REFLECT_ENUM"
    obj.fields = fields

    return obj
  end

end 

def cut_one_word(data)
  return nil if data == nil
  if (data[0].downcase >= 'a' && data[0].downcase <= 'z')
    len = data.size
    idx = len
    for i in 0...len
      if !(data[i].downcase >= 'a' && data[i].downcase <= 'z') && data[i] != ':' && data[i] != '_'
        idx = i;
        break
      end
    end

    return [data[0...idx], data[idx...len]]
  end
  start_idx = nil
  len = data.size
  return nil if data.index('(') == nil
  for i in 0...len
    if data[i] != '(' && data[i] != ' '
      start_idx = i;
      break
    end
  end
  return nil if start_idx == nil

  len = data.size
  data = data[start_idx ... len]
  end_idx = data.index(")")
  res = data[0...end_idx]

  return [res, data[end_idx + 1 ... data.size ] ]
end

# This is a temporary decision for solving problem with typedef structures like in file database_api/forward.hpp
# TODO: write a solution which searchs and generates Api_typedefs hash automaticly
Api_typedefs = {
  "golos::plugins::database_api::change_recovery_account_request_api_object" => "golos::chain::change_recovery_account_request_object",
  "golos::plugins::database_api::block_summary_api_object" => "golos::chain::block_summary_object",
  "golos::plugins::database_api::comment_vote_api_object" => "golos::chain::comment_vote_object",
  "golos::plugins::database_api::dynamic_global_property_api_object" => "golos::chain::dynamic_global_property_object",
  "golos::plugins::database_api::convert_request_api_object" => "golos::chain::convert_request_object",
  "golos::plugins::database_api::escrow_api_object" => "golos::chain::escrow_object",
  "golos::plugins::database_api::liquidity_reward_balance_api_object" => "golos::chain::liquidity_reward_balance_object",
  "golos::plugins::database_api::limit_order_api_object" => "golos::chain::limit_order_object",
  "golos::plugins::database_api::withdraw_vesting_route_api_object" => "golos::chain::withdraw_vesting_route_object",
  "golos::plugins::database_api::decline_voting_rights_request_api_object" => "golos::chain::decline_voting_rights_request_object",
  "golos::plugins::database_api::witness_vote_api_object" => "golos::chain::witness_vote_object",
  "golos::plugins::database_api::witness_schedule_api_object" => "golos::chain::witness_schedule_object",
  "golos::plugins::database_api::account_bandwidth_api_object" => "golos::chain::account_bandwidth_object"
}

# Here you should write absolute path to golos root folder
PATH_TO_GOLOS_FOLDER = '/home/anton/code/work/466/1/golos'

# Parsing files and searching for all reflected structure
# And getting their full description
travel(PATH_TO_GOLOS_FOLDER)
Structures.each {|name, value| value.fill_inherited_fields(name)}
# Structures.each {|name, value| puts "", value.to_s}

cpp_test_code = 
"#ifdef STEEMIT_BUILD_TESTNET


#include <boost/test/unit_test.hpp>

#include <golos/protocol/exceptions.hpp>

#include <golos/chain/block_summary_object.hpp>
#include <golos/chain/database.hpp>
#include <golos/chain/hardfork.hpp>
#include <golos/chain/history_object.hpp>
#include <golos/chain/steem_objects.hpp>

#include <golos/plugins/debug_node/plugin.hpp>

#include <fc/crypto/digest.hpp>

#include \"../common/database_fixture.hpp\"
#include \"values_random_generator.hpp\"

#include <cmath>

#include <golos/plugins/block_info/plugin.hpp>
#include \"../common/database_fixture.hpp\"

using namespace golos::chain;
using namespace golos::protocol;
#define REFLECT_TESTS_OUTPUT_FILE \"reflect_tests_output_file.txt\"




BOOST_FIXTURE_TEST_SUITE(reflect, database_fixture)


"
Structures.each {|name, value| cpp_test_code += value.get_cpp_test_case}

cpp_test_code += 
"
BOOST_AUTO_TEST_SUITE_END()
#endif
"
puts cpp_test_code
