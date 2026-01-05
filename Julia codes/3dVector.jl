struct Vector3D{T}
    x::T
    y::T
    z::T
    function Vector3D{T}(x::T,y::T,z::T) where T
        println("New 3d vector")
        return new(x,y,z)
    end
end

Vector3D{Float64}(1.0, 2.0, 3.0)

Vector3D(x::Float64, y::Float64, z::Float64)=Vector3D{Float64}(x, y, z)
Vector3D(x::Int64, y::Int64, z::Int64)=Vector3D{Int64}(x, y, z)

Vector3D(2.0, 4.0, 6.0)
Vector3D(4, 8, 12)