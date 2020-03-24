#if File.exists?("input")
#  $stdin = File.open("input")
#  $stdout = File.open("output","w")
#end

def concat(s,n,num)
  num.times do
    s=s+n
    s.slice!(0)
  end
  return s
end

#concatenates d to n num times

$str="" 

#final string value

def minimize(n,d)

  string = n.dup
  arr=string.split("")

  min=arr.min
  index = string.index(min)
  
  max = arr.max

  if(d<min)  #return string dddddd...
    string=concat(string,d,string.size)
    $str+=string
    return
  end

#  if(d>=max && string[0]==min) #return same string
#    $str+=string
#    return
#  end

  new_str = concat(string,d,index)
  $str += new_str.slice!(0) #remove most sig dig

  return minimize(new_str,d)

end

gets.chomp.to_i.times do

  arr =gets.chomp.split(" ")
  minimize(arr[0],arr[1])
  puts $str
  $str="" #reset string

end