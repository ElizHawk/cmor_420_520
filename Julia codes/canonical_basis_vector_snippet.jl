# define CanonicalBasisVector type as a new AbstractVector type
struct CanonicalBasisVector <: AbstractVector{Bool}
    length::Int64
    index::Int64
    function CanonicalBasisVector(length,index)
        return new(length,index)
    end
end

# using "import" to extend Julia's built-in functions
import Base: size, getindex
Base.size(x::CanonicalBasisVector) = (x.length, )
Base.getindex(x::CanonicalBasisVector, i) = i == x.index

import LinearAlgebra: dot
dot(x::CanonicalBasisVector, A::AbstractMatrix, y::AbstractVector)= A[x.index,:]* y
dot(x::Vector, A::AbstractMatrix, y::CanonicalBasisVector)= x'* A[:,y.index]
dot(x::CanonicalBasisVector, A::AbstractMatrix, y::CanonicalBasisVector)= A[x.index,y.index]