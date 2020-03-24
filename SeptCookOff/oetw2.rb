require 'set'

t = gets.to_i
ansarr = []

t.times do
  n = gets.to_i
  arr = gets.chomp.split(" ").map(&:to_i)
  
  totset = Set.new
  currset = Set.new
  newcurrset = Set.new

  arr.each do |z|
    newcurrset.add(z)
    currset.each do |x|
      newcurrset.add(x+z)
    end

    newcurrset.each do |x|
      if totset.include?(x)
        newcurrset.delete(x)
      else
        totset.add(x)
      end
    end
    
    currset = newcurrset
    newcurrset = Set.new
    #p currset
  end
  puts totset.size
end
