require 'set'

def strtoarr(str,n)
  arr = str.each_char.to_a.map{|x| x.to_i+1}
  while arr.length<n
    arr = [1] + arr
  end
  return arr
end

def ans(str,n)
  arr = strtoarr(str,n)
  
  set = Set.new
  arr.each_with_index do |x,i|
    arr.each_with_index do |y,j|
      set.add(arr[i..j].inject(:+))
    end
  end

  set.delete(nil)
  return set.size
end

x = 6
(0..(2**x-1)).each do |z|
  puts "#{strtoarr(z.to_s(2),x)} => #{ans(z.to_s(2),x)}"
end
