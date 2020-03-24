t = gets.to_i
arr = []
t.times {arr.push gets.to_i} 

arr.each do |n|

  byts = (n/26)
  modts = n%26

  if (modts==0)
    puts "0 0 #{2**(byts-1)}"
  elsif(modts<=2)
    puts "#{2**byts} 0 0"
  elsif(modts<=10)
    puts "0 #{2**byts} 0"
  else
    puts "0 0 #{2**byts}"
  end
end

=begin
  hash = Hash.new([0,0,0])
  hash[0] = [1,0,0] #hash represents the number of items created or destroyed on that millisecond

  (1..n).each do |x|
    asd = [0,0,0]
    asd[1] = hash[x-2][0] - hash[x-8][1]
    asd[2] = hash[x-8][1] - hash[x-16][2]
    asd[0] = hash[x-16][
=end
