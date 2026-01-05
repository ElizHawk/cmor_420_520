struct my_vector <: AbstractVector{Int64}
    x::Int64
    y::Int64
    function my_vector(x,y)
        return new(x,y)
    end
end

# using "import" to extend Julia's built-in functions
import Base: size, getindex
Base.size(x::my_vector) = 2
Base.getindex(vec::my_vector, i) = ((i==1)*vec.x+(i==2)*vec.y)


