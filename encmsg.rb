t = gets.to_i
arr = []
narr = []
t.times do
  narr.push gets.to_i
  arr.push gets.chomp
end

def switch(str,len)
  (0..(len/2)-1).each do |x|
    str[2*x],str[2*x+1] = str[2*x+1],str[2*x]
  end
  return str
end

def change(str)
  newstr = ""
  str.each_char do |x|
    newstr += ((26-(x.ord-97))+96).chr
  end
  newstr
end

(0..t-1).each do |x|
  n = narr[x]
  str = arr[x]
  puts change(switch(str,n))
end
