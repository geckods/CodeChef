t = gets.to_i
ansarr = []

t.times do
  n = gets.to_i
  arr = gets.chomp.split(" ").map(&:to_i)
  
  ans = arr[0]
  
  (1..n-1).each do |i|
    ans = ans|(ans<<(arr[i]))
  end

  ansarr.push ans.to_s(2).count('1')
end
puts ansarr
