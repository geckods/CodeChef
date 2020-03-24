#HMAPPYGEN
=begin
n = 1+rand(3)
q = 1+rand(3)
k = 1+rand(3)

arr = ""
n.times do
  arr += rand(2).to_s
  arr += " "
end

qstr = ""
q.times do
  if rand(2)==0
    qstr += "?"
  else
    qstr += "!"
  end
end

puts "#{n} #{q} #{k}"
puts arr
puts qstr
=end
#HMAPPY ALL GEN

n = 3

q = n*2+1

(0..2**n-1).each do |num|
  str = num.to_s(2).rjust(n,"0").each_char.to_a.join(" ")
  qst = "?!"*n
  qst += "?"
  (1..n).each do |k|
  
    puts "#{n} #{q} #{k}"
    puts str
    puts qst
    gets
  end
end
