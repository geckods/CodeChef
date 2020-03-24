def computefor(n,k)
  korig = k
  if n==2
    return 0.5
  end
  while(k>0 and n>1)
    k-=1
    if (k==(korig-1) and n%4==2)
      n = (n/2.0)+1
    else
      n = n/2.0
      n = n.ceil.to_f
    end
  end
  if n==0
    return 1.0
  end
  return 1.0/n
end

t = gets.to_i
arr = []
t.times {arr.push gets.chomp.split(" ").map(&:to_f)}


arr.each do |nk|
  n = nk[0]
  k = nk[1]
  ans = computefor(n,k)
  puts sprintf('%.6f', ans)
end
