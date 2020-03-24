require 'set'

t = gets.to_i
nkxarr = []
seqarr = []


t.times do
  nkxarr.push gets.chomp.split(" ").map(&:to_i)
  seqarr.push gets.chomp.split(" ").map(&:to_i)
end

t.times do |i|
  nkx = nkxarr[i]
  n = nkx[0]
  k = nkx[1]
  x = nkx[2]

  kset = Set.new(seqarr[i])

  sum = seqarr[i].inject(:+)
  min = kset.min

  #puts "HI #{sum}"
  max = min+x

  sum += max*(n-k)
  sum -= ((n-k-1)*(n-k))/2

  #puts "HI #{sum}"
  a = max-n+k

  kset.each do |z|
    if z>=max-n+k+1 and z<= max
      #puts n.to_s + k.to_s + z.to_s + sum.to_s
      while (kset.include?(a))
        a-=1
      end 
      sum-=(z-a)
      a-=1
    end
  end

  #puts "THE SUM IS" + sum.to_i.to_s
  puts sum.to_i
end
