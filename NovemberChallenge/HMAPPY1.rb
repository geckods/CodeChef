#brute

nqk = gets.chomp.split(" ").map(&:to_i)

n = nqk[0]
q = nqk[1]
k = nqk[2]

arr = gets.chomp.split(" ").map(&:to_i)
qstr = gets.chomp.each_char.to_a.map{|x| x=="?"}

def longest(arr)
  currcount = 0
  maxcount = 0
  arr.each do |x|
    if x==1
      currcount+=1
    else
      if currcount>maxcount
        maxcount = currcount
      end
      currcount=0
    end
  end
  if currcount>maxcount
    maxcount = currcount
  end
  return maxcount
end

count = 0
qstr.each do |q|
#  puts "COUNT #{count%n}"
  if q
#    p arr
    puts [longest(arr),k].min
  else
    count += 1
    arr = arr.rotate(-1)
  end
end
