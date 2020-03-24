require 'set'


t = gets.to_i
mainarr = []

t.times do
  gets
  mainarr.push gets.chomp.split(" ").map(&:to_i)
end

def checkprime(x)
  if x== 2
    return true
  end

  (2..x**0.5).each do |y|
    if x%y==0
      return false
    end
  end

  return true
end

$primes = []
(2..100).each do |x|
  $primes.push x if checkprime(x)
end

$moreprimes = []
(100..100000).each do |x|
  $moreprimes.push x if checkprime(x)
end

def hasthreefacs(x)
  s = Set.new
=begin  
  count = 0
  while x%2==0
    count += 1
    x/=2
  end
  
  if count > 2
    s.add(2)
  end

  z = 3
  while(z<=[x**0.5,100].min)
    count = 0
    while x%z==0
      count +=1
      x/=z
    end
    if count>2
      s.add(z)
    end
    z += 2
  end
  return s
=end

  $cubes.each do |cube|
    break if cube>x
    s.add(cube) if x%cube==0
  end

  return s
end


def primefacs(x)
  s = Set.new
  #h = Hash.new(0)
  while x%2==0
    x/=2
    s.add(2)
#    h[2]+=1
  end

  z = 3
  while z<=(x**0.5)
    while x%z==0
      x = x/z
      s.add(z)
#      h[z]+=1
    end
    z += 2
  end

  if x>2
    s.add(x)
#    h[x]+=1 
  end

  return s
end

def no_of_divisions(x,z)
  ans = 0
  while x%z==0
    x/=z
    ans+=1
  end
  return ans
end


def redist(arr,x)
  ans = 0
  target = 1
  newarr = arr.map{|z| no_of_divisions(z,x)}
  #p newarr

  while true
    addable = 0
    newarr.each do |x|
      if x>target+1
        addable+= (x-target)/2
      end
    end
    required = 0
    newarr.each do |x|
      if x<target
        required+= target-x
      end
    end

#    p target
#    p addable
#    p required
#    puts
    
    if required>addable
      return target-1
#    elsif required==addable
#      return target
    else
      target += 1
    end
  end
end

def commondivisor(arr,x)
  min = 1.0/0.0
  arr.each do |z| 
    k = no_of_divisions(z,x)
    if k==0
      return 0
    end
    if min>k
      min = k
    end
  end
  return min
end



mainarr.each do |arr|
  #primeset = Set.new
  ans = 1
  #three = false
  arr.sort!
=begin
  arr.each do |x|
    hasthreefacs(x).each do |pr|
      #p pr
      three = true
      if primeset.include?(pr)
        next
      else
#        puts "PR:#{pr} redist#{redist(arr,pr)}"
#        p arr
#        p 
#        puts
        ans*= (pr**redist(arr,pr))
        primeset.add(pr)
      end
    end
  end
=end

  min = arr[0]

  $primes.each do |pr|
#    break if cube > min
#    puts "PR:#{pr} redist#{redist(arr,pr)}"
#    p arr 
#    puts
#    pr = pr**(1.0/3)
    ans*= (pr**redist(arr,pr))
  end

#  p ans

  ($moreprimes&primefacs(min).to_a).each do |pr|
    break if pr>min
    ans*= pr**commondivisor(arr,pr)
  end

#  if not three
#    puts 'hi'
#  end

  puts ans.to_i
end
