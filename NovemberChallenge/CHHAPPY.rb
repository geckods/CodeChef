t = gets.to_i

t.times do
  n = gets.to_i
  an = gets.chomp.split(" ").map(&:to_i)
  aan = Array.new
  (0..n-1).each do |i|
    aan[i] = an[an[i]-1]
  end
  histhash = Hash.new(-1)
  
  done = false
  (0..n-1).each do |i|
    unpack = histhash[aan[i]] 
    if unpack == -1
      histhash[aan[i]] = i
    else
      if an[i] != an[unpack]
        #DONE
        done = true
        break
      else
        next
      end
    end
  end

  if done
    puts "Truly Happy"
  else
    puts "Poor Chef"
  end
end
