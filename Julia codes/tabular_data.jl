using CSV
using DataFrames

path = joinpath(pkgdir(DataFrames), "docs", "src", "assets", "german.csv");
german = CSV.read(path, DataFrame)

# accessor functions
german[1:10, ["id", "Age"]]
german.Age
german[:, Not("Age")]
german[:, Between(:Sex, :Housing)]
german[:, Cols("Age", Between("Sex", "Housing"))]

# get stats
describe(german)
describe(german, cols=1:3)
show(german, allrows=true)

# add new cols
df1 = german[1:6, 2:4]
df1[:, :new_column] .= "no data" 
insertcols!(df1, 1, :Country => "India")

# replace data
df1.Age .= 1
df1[!, "Age"] .= "10" # "!" force overwrites the type

# slicing and modifying a dataframe
select(german, :Age, :Age => ByRow(sqrt) => :Age_square_root)
transform(df1, :Age => maximum)
transform(german, :Age => :Sex, :Sex => :Age) # swap

