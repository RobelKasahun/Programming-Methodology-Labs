//
//  Artwork_Artist.cpp
//  ArtGallerySimplified
//
//  implement/define the functions declared in "Artwork_Artist.h"
//
//created by [ Robel K Ayelew ] 
//date: 

#include "Artwork_Artist.h"

namespace NS_ARTGALLERY {

    //***implement all the functions declared in "Artwork_Artist.h"

    /** Artwork implementations **/
    Artwork::Artwork()
        : ID{-1}, artistID{-1}, type{ArtType::painting}, style{ArtStyle::fineArt},
        subject{ArtSubject::nature}, yearMade{2022}, width{0.00}, height{0.00}, depth{0.00},
        price{0.00} {
    }

    // Mutators 
    void Artwork::setID(int newID) {
        ID = newID;
    }

    void Artwork::setArtistID(int newID) {
        artistID = newID;
    }

    void Artwork::setType(ArtType theType) {
        type = theType;
    }

    void Artwork::setStyle(ArtStyle theStyle) {
        style = theStyle;
    }

    void Artwork::setSubject(ArtSubject theSubject) {
        subject = theSubject;
    }

    void Artwork::setYearMade(int year) {
        yearMade = year;
    }

    void Artwork::setDimension(double w, double h, double d) {
        width = w;
        height = h;
        depth = d;
    }

    void Artwork::setPrice(double thePrice) {
        price = thePrice;
    }

    // Accessors
    int Artwork::getID() const {
        return this->ID;
    }

    int Artwork::getArtistID() const {
        return this->artistID;
    }

    ArtType Artwork::getType() const {
        return this->type;
    }

    ArtStyle Artwork::getStyle() const {
        return this->style;
    }

    ArtSubject Artwork::getSubject() const {
        return this->subject;
    }

    int Artwork::getYearMade() const {
        return this->yearMade;
    }

    double Artwork::getWidth() const {
        return this->width;
    }

    double Artwork::getHeight() const {
        return this->height;
    }

    double Artwork::getDepth() const {
        return this->depth;
    }

    double Artwork::getPrice() const {
        return this->price;
    }
    /** End of Artwork implementations **/


    /** Artist implementations **/
    Artist::Artist(): ID{-1}, name{"na"},
        email{"na"}, birthYear{1900}, birthPlace{"na"}, primaryArtType{ArtType::painting} {
    }

    // Mutators
    void Artist::setID(int theID) {
        ID = theID;
    }

    void Artist::setName(std::string theName) {
        name = theName;
    }

    void Artist::setEmail(std::string theEmail) {
        email = theEmail;
    }

    void Artist::setBirthYear(int theYear) {
        birthYear = theYear;
    }

    void Artist::setBirthPlace(std::string thePlace) {
        birthPlace = thePlace;
    }

    void Artist::setPrimaryArtType(ArtType theType) {
        primaryArtType = theType;
    }

    // Accessors 
    int Artist::getID() const {
        return this->ID;
    }
    //returns an artist's name
    std::string Artist::getName() const {
        return this->name;
    }

    std::string Artist::getEmail() const {
        return this->email;
    }

    int Artist::getBirthYear() const {
        return this->birthYear;
    }

    std::string Artist::getBirthPlace() const {
        return this->birthPlace;
    }

    ArtType Artist::getPrimaryArtType() const {
        return this->primaryArtType;
    }
    /** End of Artist implementations **/

}//end-of NS_ARTGALLERY