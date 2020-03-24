n = gets.to_i
nf = n.to_f
arr = Array.new
hash = Hash.new(0)

sim = 1000000

sim.times do
  arr = []
  (1..n).each {|z| arr.push z}

  (0..n-1).each do |i| 
    j = rand(n)
    arr[i],arr[j] = arr[j],arr[i]
  end

  hash[arr]+=1
end

p hash.sort_by{|a,b| b}
