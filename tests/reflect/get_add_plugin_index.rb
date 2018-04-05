# Prints all usages of "add_plugin_index"
Ans = []

def travel(path) 

  Dir.foreach(path) do |item|
    next if item == '.' or item == '..'
    np = path + "/" + item
    next if item == "tests"
    if File.directory?(np)
      travel(np)
    else
      next if item == "reflect.hpp"
      s = File.basename(np).split('.')[-1]

      if s == "h" || s == "hpp" || s == "cpp"
        pattern = "add_plugin_index"
        f = File.open(np, "r") 
        f.each_line do |line|
          Ans << line if line.index(pattern)
        end
      end

    end
  end
   
end


# Here you should write absolute path to golos root folder
PATH_TO_GOLOS_FOLDER = '/home/anton/code/work/466/1/golos'

travel(PATH_TO_GOLOS_FOLDER)

Ans.each {
  |x|  x = x.delete(' ')
  puts x
}