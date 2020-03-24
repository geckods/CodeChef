#brute force

t = gets.to_i

def median(array)
  sorted = array.sort
  len = sorted.length
  (sorted[(len - 1) / 2] + sorted[len / 2]) / 2.0
end

t.times do
  n = gets.to_i
  arr= gets.chomp.split(" ").map(&:to_i)
  ans = 0
  (1..2**n-1).each do |x|
    bin = x.to_s(2).rjust(n,"0")
    newarr = []
    bin.each_char.with_index do |ch,i|
      if ch=="1"
        newarr.push arr[i]
      end
    end

    if newarr.include?(median(newarr))
      ans+=1
#      puts bin if bin.count("1")%2==0
    end 
  end
  puts ans%1000000009
end
