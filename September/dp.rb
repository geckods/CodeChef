$hash = Hash.new(0)
$dp = Hash.new(nil)

def merge(hash1,hash2)
  hash2.each do |k,v|
    hash1[k]+=v
  end
  return hash1
end

$dpcount = 0
def comp(arr,depth)

  ans = $dp[[arr.dup,depth]]
  if not ans.nil?
    $dpcount+=1
    return ans
  end

  hash = Hash.new(0)
  if depth<arr.length
    (0..arr.length-1).each do |x|
      arr[depth],arr[x] = arr[x],arr[depth]
      hash = merge(hash,comp(arr,depth+1))
      arr[x],arr[depth] = arr[depth],arr[x]
    end
    $dp[[arr.dup,depth]] = hash
    return hash
  else
    return {arr.dup => 1}
  end
end


comp([1,2,3,4,5,6,7],0).sort_by{|k,v| v}.each do |a|
  puts "#{a[0]} => #{a[1]}"
end
puts $dpcount
