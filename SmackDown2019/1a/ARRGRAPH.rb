require 'set'

def checkprime(x)
  (2..x**0.5).each do |z|
    return false if x%z==0
  end
  return true
end

def primefactors(x)
  ans = Set.new()
  
  if checkprime(x)
    ans.add(x)
    return ans
  end

  (2..(Math.sqrt(x)+1).to_i).each do |z|
    if(x%z==0)
      ans.add(z) if checkprime(z)
      ans.add(x/z) if checkprime(x/z)
    end
  end
  return ans
end

hash = Hash.new(Set.new)

(2..50).each do |x|
  hash[x] = primefactors(x)
end

t = gets.to_i

def gcd(a, b)
  b == 0 ? a : gcd(b, a.modulo(b))
end

$max = 1
(1..50).each do |z|
  $max*=z
end

def checkarr(arr)
  arr.each do |x|
    xisok = false
    (arr-[x]).each do |y|
      if (gcd(x,y)==1)
        xisok = true
        break
      end
    end

    if not xisok
      return false
    end
  end
  return true
end

def nicep(arr)
  arr.each do |x|
    print "#{x} "
  end
  puts
end

mainarr = []
t.times do
  n = gets.to_i
  arr = gets.chomp.split(" ").map(&:to_i)
  mainarr.push arr
end

mainarr.each do |arr|
  if checkarr(arr) or arr.length==1
    puts 0
    nicep arr
  else
    puts 1
    if arr[0] == 29
      arr[0] = 37
    else
      arr[0] = 29
    end
    nicep arr
  end
end
    
  
