nq = gets.chomp.split(" ").map(&:to_i)
arr = gets.chomp.split(" ").map(&:to_i)
qarr = []
n = nq[0]
q = nq[1]
q.times {qarr.push gets.chomp.split(" ").map(&:to_i)}

def nicep(arr)
  arr.each do |x|
    p x
  end
end

arr = arr.map{|x| x.to_s(2).rjust(30,"0")}

bitarr = []

(0..29).each do |whichbit|
  iterat = n-1
  while iterat>=0
    if arr[iterat][whichbit] == "1"
      bitarr[whichbit] = iterat
      break
    end
    iterat-=1
  end
end

startarr = []

nicep arr
(0..29).each do |whichbit|
  constr = ""
  iterat = n-1
  while iterat>=0
    constr = arr[iterat][whichbit] +  constr
    iterat-=1
  end
#  p constr
  startarr.push constr.to_i(2)
end

p startarr

nicep arr

qarr.each do |quer|
  k = quer[0]
  x =  quer[1]

  puts "THIS IS K AND X"
  puts k
  puts x


  toconstr = 0

  (0..29).each do |bit|
    next if bitarr[bit].nil?
    thenum = startarr[bit]+k*(2**(n-bitarr[bit]))
    thebit = 0
    thebit = 1 if ((thenum)&(2**(n-x-1)) > 0)

    toconstr += thebit*(2**(29-bit))
    puts "#{startarr[bit]} #{k*(2**(n-bitarr[bit]))} #{bit} #{thenum} #{thebit}"
    puts startarr[bit].to_s(2)
    puts (k*(2**(n-bitarr[bit]))).to_s(2) 
    puts thenum.to_s(2)
    puts (2**(n-x-1)).to_s(2)
    puts thebit
  end
  puts "ANS:"
  puts toconstr
end
