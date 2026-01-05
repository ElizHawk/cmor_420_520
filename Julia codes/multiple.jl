my_norm(x,y,z)=sqrt(x^2+y^2+z^2)

function my_norm(x::Vector, y::Vector, z::Vector)
    return @. mynorm(x,y,z)
end

function my_norm(message::String, x, y, z)
    println(message)
    return mynorm(x,y,z)
end


function my_norm(x::Int64, y::Int64, z::Int64)
    println("running specialized version")
    return sqrt(x^2+y^2+z^2)
end

