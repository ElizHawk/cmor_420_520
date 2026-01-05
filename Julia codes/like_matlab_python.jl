for i in 1:100
    if (i % 2 == 0)
        # do something 
    elseif (i < 10)
        # do something else
    else
        # ...
    end
end


# ranges in Julia
i = 0:10
a = LinRange(-1, 2, 1000)

# an array comprehension
b = [2 * i for i in 1:10]

# tuples in Julia
c = ("hi", 1, 3.0)

# named tuples
d = (; a = "hi", b = 1, 
       c = 3.0)
d.a # returns "hi"