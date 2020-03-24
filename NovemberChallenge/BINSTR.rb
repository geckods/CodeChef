hash = Hash.new

nq = gets.chomp.split(" ").map(&:to_i)
n = nq[0]
q = nq[1]
numarr = []

maxlen = 0
n.times do
  thestr = gets.chomp
  len = thestr.length
  numarr.push thestr
  maxlen = len if len>maxlen
end

querrarr = []
q.times do
  querrarr.push gets.chomp.split(" ").map(&:to_i)
end

numarr = numarr.map{|x| x.rjust(maxlen,"0")}
p numarr

#Segment tree of sets that have string prefixes?
