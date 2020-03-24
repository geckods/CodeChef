puts 1
n = rand(10)
puts n
arr = []
n.times {arr.push rand(4)}

arr.each_with_index do |x,i|
  if x==0
    arr[i] = -1
  end
end

arr.each do |x|
  print "#{x} "
end
puts
