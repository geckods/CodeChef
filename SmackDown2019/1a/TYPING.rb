t = gets.to_i

narr = []
wordsarr = []

t.times do
  n = gets.to_i
  narr.push n
  temparr = []
  n.times {temparr.push gets.chomp}
  wordsarr.push temparr
end

def isleft(char)
  return (char=="d" || char=="f")
end


def findtime(word)
  time = 2
  curr = isleft(word[0])

  (1..word.length-1).each do |charind|
    now = isleft(word[charind])
    
    if(curr^now) #different hand
      time+=2
    else
      time+=4
    end
    curr = now.dup
  end

  return time
end
      

wordsarr.each do |words|
  hash = Hash.new(0)
  tottime = 0

  words.each do |word|
    if hash[word] == 0
      thistime = findtime(word)
      hash[word] = thistime
      tottime += thistime
    else
      tottime += hash[word]/2
    end
  end

  puts tottime
end
