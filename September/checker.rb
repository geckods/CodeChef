$hash = Hash.new(0)
$dp = Hash.new(Hash.new(0))
def comp(arr,depth)
  #if $dp[[arr,depth]]
  if depth<arr.length
    (0..arr.length-1).each do |x|
      arr[depth],arr[x] = arr[x],arr[depth]
      comp(arr,depth+1)
      arr[x],arr[depth] = arr[depth],arr[x]
    end
  else
    $hash[arr.dup]+=1
  end
end

comp([1,2,3,4,5,6,7,8,9],0)
$hash.sort_by{|k,v| v}.each do |a|
  puts "#{a[0]} => #{a[1]}"
end
