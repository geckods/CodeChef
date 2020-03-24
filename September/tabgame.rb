t = gets.to_i

def nicep arr
  arr.each {|x| p x}
end

def nor(a,b)
  return 1-(a|b)
end
  

t.times do
  arr1 = gets.chomp.split("").map(&:to_i)
  arr2 = gets.chomp.split("").map(&:to_i)
  m = arr1.length
  n = arr2.length

  arr = Array.new
  (n+1).times {arr.push [0]*(m+1)}

  (1..n).each do |z|
    arr[z][0] = 1-arr2[z-1]
  end

  (1..m).each do |z|
    arr[0][z] = 1-arr1[z-1]
  end
#  nicep arr
  (2..n+m).each do |sum|
    (1..sum-1).each do |i|
      j = sum-i
      next if i>n or j>m
      arr[i][j] = nor(arr[i][j-1],arr[i-1][j])
    end
  end

  nicep arr
      
  q = gets.to_i
  ansarr = []

  q.times do
    query = gets.chomp.split(" ").map(&:to_i)
    ansarr.push 1-arr[query[0]][query[1]]
#    p query
#    p ansarr
  end
  puts ansarr.join("")
end
