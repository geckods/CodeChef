t = gets.to_i
ansarr = []

t.times do
  n = gets.to_i
  arr = gets.chomp.split(" ").map(&:to_i)
  
  c = 0
  g = 0
 
  hasseentwo = false

  arr.each do |z|
    if z==1
      c += (g+1)
      g = 0
    else
      if (not hasseentwo) and (c != 0)
        c += 1
      end
      hasseentwo = true
      c += 1
      g += 1
    end
  end  
  ansarr.push c
end
puts ansarr
