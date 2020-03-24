require 'set'
t = gets.to_i
ansarr = []
t.times do
  n = gets.to_i
  arr = gets.chomp.split(" ").map(&:to_i)
  set = Set.new(arr)
 
  count = 0
  (1..n).each do |x|
    count += 1 unless set.include?(x)
  end

  ansarr.push count
end

puts ansarr
