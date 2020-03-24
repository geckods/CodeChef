def debug a
#  puts a
end

def debug2 a
#  puts a
end

def givesquare(a,b,x,y,n,m)

#  debug2 "#{a} #{b} #{x} #{y} #{n} #{m}"

  if a==x and b==y
    return 0
  end

  ans = 0
  #a,b is my position
  #x,y is his position

  #look up
  if b==y and x<a
    ans += a-x-1
  else
    ans += a-1
  end
#  debug "UP:" + ans.to_s

  #look down
  if b==y and x>a
    ans += x-a-1
  else
    ans += n-a
  end
#  debug "DOWN:" + ans.to_s
  #look right
  if a==x and y>b
    ans += y-b-1
  else
    ans += m-b
  end
#  debug "RIGHT:" + ans.to_s
  #look left
  if a==x and y<b
    ans += b-y-1
  else
    ans += b-1
  end
#  debug "LEFT:" + ans.to_s
  #look upleft
  if (x-y == a-b) and x<a
    ans += a-x-1
  else
    ans += [a-1,b-1].min
  end
#  debug "UPLEFT:" + ans.to_s
  #look downright
  if (x-y == a-b) and x>a
    ans += x-a-1
  else
    ans += [n-a,m-b].min
  end
#  debug "DOWNRIGHT:" + ans.to_s
  #look upright
  if (x+y == a+b) and y>b
    ans += y-b-1
  else
    ans += [a-1,m-b].min
  end
#  debug "UPRIGHT:" + ans.to_s
  #look downleft
  if (x+y == a+b) and y<b
    ans += b-y-1
  else
    ans += [n-a,b-1].min
  end
#  debug "DOWNLEFT:" + ans.to_s
  return ans
end

t = gets.to_i
arr = []
t.times {arr.push gets.chomp.split(" ").map(&:to_i)}

arr.each do |nmxy|
  n = nmxy[0]
  m = nmxy[1]
  x = nmxy[2]
  y = nmxy[3]

  ans = 0
  (1..n).each do |a|
    (1..m).each do |b|
      next if a==x and b==y
      ans += (n*m)-givesquare(a,b,x,y,n,m)-2
#      puts "#{a} #{b} #{givesquare(a,b,x,y,n,m)}"
    end
  end
  puts ans
end
