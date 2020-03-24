stuff = gets.chomp.split(" ").map(&:to_i)

t = stuff.shift

def findans(n)
  left = 0.0
  right = 1.0
  toflipright = true

  n.times do
    if toflipright
      toflipright = false
      right = (left+right)/2.0
    else
      toflipright = true
      left = (left+right)/2.0
    end
  end

  if toflipright
    return left
  else
    return right
  end
end

def findansxy(n)
  left = 0.0
  right = 1.0
  toflipright = true

  n.times do
    if toflipright
      toflipright = false
      right = (left+right)/2.0
    else
      toflipright = true
      left = (left+right)/2.0
    end
  end

  if toflipright
    return left
  else
    return right
  end
end

stuff.each do |i|
  asd = findans(i)
  den = 1
  while asd != asd.to_i
    asd*=2
    den*=2
  end
  print "#{asd.to_i} #{den.to_i} "
end
puts
