t = gets.to_i

nmarr = []
mainarr = []

t.times do
  nm = gets.chomp.split(" ").map(&:to_i)
  nmarr.push nm
  temp = []
  nm[0].times do
    asd =  gets.chomp.split("").map(&:to_i)
    temp.push asd
  end
  mainarr.push temp
end

(0..t-1).each do |no|
  arr = mainarr[no]
  nm = nmarr[no]

  n = nm[0]
  m = nm[1]

  newarr = []
  n.times do
    temp = []
    m.times do
      temp.push "X"
    end
    newarr.push temp
  end

#  arr.each do |row|
#    p row
#  end
#  puts
  hasone = false

  arr.each_with_index do |row,i|
    row.each_with_index do |y,j|
      if y==1
        hasone = true
        newarr[i][j] = 0
      end
    end
  end

  if not hasone
    n.times do
      puts "-1 "*m
    end
    next
  end

  newarr.each_with_index do |row,i| #row-wise
    row.each_with_index do |y,j|
      #puts "#{i} #{j}"
      if y==0
        (0..m-1).each do |z|
          if newarr[i][z] == "X"
            newarr[i][z] = 1
          end
        end
        break
      end
    end
  end

  (0..m-1).each do |j|
    (0..n-1).each do |i|
      if newarr[i][j]==0

        (0..n-1).each do |z|
          if newarr[z][j] === "X"
            newarr[z][j] = 1
          end
        end
        break
      end
    end
  end
      
  newarr.each do |row|
    row.map{|x| (x=="X")?2:x}.each do |item|
      print "#{item} "
    end
    puts
  end
end
