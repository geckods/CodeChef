t = gets.chomp
arr = []
t.times {arr.push gets.chomp.split(" ").map(&:to_i)}

arr.each do |nd|
  n = nd[0]%9
  d = nd[1]%9

  if(n==1)
    puts "1 "
