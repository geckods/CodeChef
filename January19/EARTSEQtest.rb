def gcd(a,b)
  if a==0
    return b
  end
  return gcd(b%a,a)
end

def get_all_pairs(arr)
  newarr = arr.each_cons(2).to_a
  newarr.push [arr[-1],arr[0]]
  return newarr
end
 
def get_all_triplets(arr)
  newarr = arr.each_cons(3).to_a
  newarr.push [arr[-2],arr[-1],arr[0]]
  newarr.push [arr[-1],arr[0],arr[1]]
  return newarr
end

 
def validate_arr(arr)
  get_all_pairs(arr).each do |p|
    if gcd(p[0],p[1]) == 1
      p p
      return false
    end
  end

  get_all_triplets(arr).each do |t|
    if(gcd(t[0],gcd(t[1],t[2])) != 1)
      p t
      p gcd(t[0],gcd(t[1],t[2]))
      return false
    end
  end
  return true
end

arr = "6 15 35 63 99 143 195 255 323 399 483 575 675 783 899 1023 1155 1295 1443 1599 1763 1935 2115 2303 2499 2703 2915 3135 3363 3599 3843 4095 4355 4623 4899 5183 5475 5775 6083 6399 6723 7055 7395 7743 8099 8463 8835 9215 9603 9999 10403 10815 11235 11663 12099 12543 12995 13455 13923 14399 14883 15375 15875 16383 16899 17423 17955 18495 19043 19599 20163 20735 21315 21903 22499 23103 23715 24335 24963 25599 26243 26895 27555 28223 28899 29583 30275 30975 31683 32399 33123 33855 34595 35343 36099 36863 37635 38415 39203 39999 40803 83230".split(" ").map(&:to_i)
p validate_arr(arr)