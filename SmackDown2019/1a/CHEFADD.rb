=begin
a = 369
b = 428
sum = a+b
len = sum.to_s(2).length

as = a.to_s(2).rjust(len,"0")
bs = b.to_s(2).rjust(len,"0")
sums = sum.to_s(2)
=end

=begin
p as
p bs
p sums
puts
=end

=begin
origincount = 0

as.each_char.to_a.permutation(len).uniq.each do |x|
  bs.each_char.to_a.permutation(len).uniq.each do |y|
    if (x.join.to_i(2) + y.join.to_i(2) == sum)
      puts x.join
      puts y.join
      puts
      origincount+=1
    end
  end
end
=end


$fulladder = {0=>[[0, 0, 0], [1, 1, 1]], 1=>[[0, 1, 1], [1, 0, 1]], 10=>[[0, 1, 0], [1, 0, 0]], 11=>[[0, 0, 0], [1, 1, 1]]} 

def coolrecursion(targetstring,az,ao,bz,bo,ci)
  #puts targetstring.length
  if targetstring.length==0
    return 1-ci
  end
  count = 0
  togetsum = targetstring[0].to_i

  $fulladder[togetsum*10+ci].each do |poss|
    newaz = az
    newao = ao
    newbz = bz
    newbo = bo

    possa = poss[0]
    possb = poss[1]
    possco = poss[2]

    if possa==0
      newaz-=1
    else
      newao-=1
    end

    if possb==0
      newbz-=1
    else
      newbo-=1
    end

    next if [newaz,newao,newbz,newbo].min<0
      
    count+=coolrecursion(targetstring[1..-1],newaz,newao,newbz,newbo,possco)
  end
  return count
end

$tp = Hash.new(-1)
def coolrecursionint(targetint,az,ao,bz,bo,ci,log)
  #puts targetstring.length
  ans = $tp[[targetint,az,ao,bz,bo,ci,log]]
  if ans !=-1
    return ans
  end


  if log==0
    return 1-ci
  end
  count = 0
  togetsum = targetint/log

  $fulladder[togetsum*10+ci].each do |poss|
    newaz = az
    newao = ao
    newbz = bz
    newbo = bo

    possa = poss[0]
    possb = poss[1]
    possco = poss[2]

    if possa==0
      newaz-=1
    else
      newao-=1
    end

    if possb==0
      newbz-=1
    else
      newbo-=1
    end

    next if [newaz,newao,newbz,newbo].min<0
      
    count+=coolrecursionint(targetint%log,newaz,newao,newbz,newbo,possco,log/2)
  end

  $tp[[targetint,az,ao,bz,bo,ci,log]] = count
  return count
end

t = gets.to_i
arr = []
t.times do
#  a = rand(100000)
#  b = rand(100000)
#  c = a+b
  abc = gets.chomp.split(" ").map(&:to_i)
  arr.push abc
end

arr.each do |abc|
  a = abc[0]
  b = abc[1]
  sum = abc[2]
  sums = sum.to_s(2)
  len = sums.length

  thelog = Math.log(sum,2).to_i
  themax = 2**thelog

  as = a.to_s(2).rjust(len,"0")
  bs = b.to_s(2).rjust(len,"0")

  sumrev = sum.to_s(2).reverse.to_i(2)

  puts coolrecursionint(sumrev,as.count("0"),as.count("1"),bs.count("0"),bs.count("1"),0,themax)
end
