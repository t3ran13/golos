
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

  puts ""
  path_to_print = path[path.index("golos")...path.size]
  puts path_to_print

  for i in 0...res.size
    puts res[i]
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
  for i in (first_parenthesis_idx) ... data.size
    counter += 1 if data[i] == '('
    counter -= 1 if data[i] == ')'
    if counter == 0 
      last_parenthesis_idx = i
      break
    end
  end

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

travel(PATH_TO_GOLOS_FOLDER)
