t = gets.to_i
arr = []
karr = []

t.times do
  karr.push gets.chomp.split(" ").map(&:to_i)[1]
  arr.push gets.chomp.split(" ").map(&:to_i)
end

arr.each_with_index do |x,i|
  sum = 0

  x.each_with_index do |bit,j|
    if j%2==0
      if sum>0
        sum += bit
      else
        sum -= bit
      end
    else
      if sum>0
        sum-=bit
      else
        sum+= bit
      end
    end
  end

  if sum.abs>=karr[i]
    puts 1
  else
    puts 2
  end
end

