# import required libraries
import imdb
import sys

# define a function to print names from a list
def namesInList(nameList):
	names=''
	# for each person object, extracts name tag and append to our names string
	if nameList is None: return ''
	for i in nameList: names=names+'; '+str(i.get('name'))
	# returns final string shifted by 2 chars to manage initial " ;"
	return names[2:]


# initializes IMDb funtion and searches for our name
ia = imdb.IMDb()
var = input("Please enter the name of a movie: ")
movies = ia.search_movie(var)

film=movies[0]

filmID=film.movieID

# getting information
series = ia.get_movie(filmID)
  
# getting rating of the series
rating = series.data['rating']
  
# printing the object i.e name
print(series)
  
# print the rating
print(rating)