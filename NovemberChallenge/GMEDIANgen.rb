puts 2
2.times do
  n = rand(100)
  puts n
  n.times{ print "#{rand(5)} "}
  puts
end
