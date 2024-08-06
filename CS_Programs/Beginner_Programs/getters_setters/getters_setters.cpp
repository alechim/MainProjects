#include <iostream>

using namespace std;

class Movie{
    private:
        // Will not allow rating to be used outside of constructor
        string rating;
    public:
        string title;
        string director;
        // string rating;
        Movie(string movieTitle, string movieDirector, string movieRating){
            title = movieTitle;
            director = movieDirector;
            // rating = movieRating;
            setRating(movieRating);
        }

        void setRating(string movieRating){
            // rating = movieRating;
            if(movieRating == "G" || movieRating == "PG" || movieRating == "PG-13" || movieRating == "R" || movieRating == "NR"){
                rating = movieRating;
            } else {
                rating = "NR";
            }
        }

        string getRating(){
            return rating;
        }
};

int main(){

    // Possible Ratings: G, PG, PG-13, R, NR
    // Nothing to prevent rating set to something else (e.g. Dog)
    Movie avengers("The Avengers", "Joss Whedon", "PG-13");

    // When set to private, rating can not be called out of constructor
    // cout << avengers.rating << endl;
    
    // avengers.rating = "Dog";
    avengers.setRating("Dog");

    cout << avengers.getRating() << endl;

    return 0;
}