n = gets.to_i

firstarray = []

(2..[n/2,2].max).each {|i| firstarray.push i}
firstarray.push 1

nextelement = 0

(1..n).each do |z|
  if not firstarray.include?(z)
    nextelement = z
    break
  end
end

(nextelement+1..n).each {|z| firstarray.push z}

firstarray.push nextelement

if n==1
  firstarray = [1]
elsif n==2
  firstarray = [2,1]
end



lastarray = []
lastarray.push n
(1..n-1).each {|x| lastarray.push x}

puts firstarray.join(" ")
puts lastarray.join(" ")

