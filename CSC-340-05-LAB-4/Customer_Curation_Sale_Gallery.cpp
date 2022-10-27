//
//  Customer_Curation_Sale_Gallery.cpp
//  ArtGallerySimplified
//
//  implement/define the member functions of the following classes:
//     1. class Customer; 2. class Curation; 3. class Sale; 4. class ArtGallery
//
// created by: [Robel K Ayelew]
// date:  

#include "Customer_Curation_Sale_Gallery.h"
#include<vector>

namespace NS_ARTGALLERY {

    template <typename T>
    bool isAvailable(T& t, std::vector<T>& vecList) {
        for (unsigned long int i = 0; i < vecList.size(); i++) {
            if ((t.getName() == vecList.at(i).getName()) && (t.getEmail() == vecList.at(i).getEmail())) {
                return true;
                break;
            }
        }
        return false;
    }

    //  implement/define the member functions of the following classes:
   //     1. class Customer; 2. class Curation; 3. class Sale; 4. class ArtGallery

   /** Customer functions implementation **/
    Customer::Customer(): ID{-1}, name{"na"}, email{"na"}, address{"na"} {
    }

    Customer::Customer(int theID, std::string theName, std::string theEmail, const std::string theAddr)
        : ID{theID}, name{theName}, email{theEmail}, address{theAddr} {
    }

    // Mutators
    void Customer::setID(int theID) {
        ID = theID;
    }

    void Customer::setName(std::string theName) {
        name = theName;
    }

    void Customer::setEmail(std::string theEmail) {
        email = theEmail;
    }

    void Customer::setAddress(std::string theAddress) {
        address = theAddress;
    }

    // Accessors
    int Customer::getID() const {
        return this->ID;
    }

    std::string Customer::getName() const {
        return this->name;
    }

    std::string Customer::getEmail() const {
        return this->email;
    }

    std::string Customer::getAddress() const {
        return this->address;
    }

    // Get artworksForSale
    std::vector<Artwork> Gallery::getArtworksForSale() const {
        return this->artworksForSale;
    }
    /** End of Customer functions implementation **/




    /*** Curation functions implementation ***/
    //default constructor: artworkID(-1),artistID(-1),curationDate({1,1,2022})
    Curation::Curation(): artworkID{-1}, artistID{-1}, curationDate{1, 1, 2022} {
    }

    Curation::Curation(int theArtworkID, int theArtistID, NS_ARTGALLERY::Date theDate)
        : artworkID{theArtworkID}, artistID{theArtistID}, curationDate{theDate} {
    }

    // Mutators
    void Curation::setArtworkID(int theID) {
        artworkID = theID;
    }

    void Curation::setArtistID(int theID) {
        artistID = theID;
    }

    void Curation::setCurationDate(Date theDate) {
        curationDate = theDate;
    }

    // Accessors
    int Curation::getArtworkID() const {
        return this->artworkID;
    }

    int Curation::getArtistID() const {
        return this->artistID;
    }

    Date Curation::getCurationDate() const {
        return this->curationDate;
    }
    /*** End of Curation functions implementation ***/




    /**** Sale functions implementation ****/
    Sale::Sale(): customerID{-1}, artworkID{-1}, saleDate{1, 1, 2022} {
    }

    Sale::Sale(int theCustomerID, int theArtworkID, Date theDate)
        : customerID{theCustomerID}, artworkID{theArtworkID}, saleDate{theDate} {
    }

    // Mutators
    void Sale::setCustomerID(int theID) {
        customerID = theID;
    }

    void Sale::setArtworkID(int theID) {
        artworkID = theID;
    }

    void Sale::setSaleDate(Date theDate) {
        saleDate = theDate;
    }

    // Accessors
    int Sale::getCustomerID() const {
        return this->customerID;
    }

    int Sale::getArtworkID() const {
        return this->artworkID;
    }

    Date Sale::getSaleDate() const {
        return this->saleDate;
    }
    /**** End of Sale functions implementation ****/




    /***** Gallery functions implementation *****/
        //default constructor: ID(-1),name("na"),address("na"),webURL("na")
    Gallery::Gallery()
        : ID{-1}, name{"na"}, address{"na"}, webURL{"na"} {
    }

    // Mutators
    void Gallery::setID(int theID) {
        ID = theID;
    }

    void Gallery::setName(string theName) {
        name = theName;
    }

    void Gallery::setAddress(string theAddr) {
        address = theAddr;
    }

    void Gallery::setWebURL(string theURL) {
        webURL = theURL;
    }

    //add an artist to the artistList. 
    // Make sure that 
    // (1) this artist is not already on artistList by checking the name & email combination; 
    // and (2) this artist has a valid ID by generating a unique ID. 
    // Do nothing if the artist is already on the list.
    //returns artistID
    int Gallery::addArtist(NS_ARTGALLERY::Artist artist) { /* PASSED */
       if (artist.getID() < 0) {
            artist.setID(NS_ARTGALLERY::uniqueIDs::next_artistID());
       }
       
       if (!isAvailable(artist, artistsList)) {
            artistsList.push_back(artist);
            return artist.getID();
       }
       std::cout << "ID: " << artist.getID() << std::endl;
       return artist.getID();
    }

    // adds a customer to the customerList. 
    // Make sure that 
    // (1) this customer is not already on customerList by checking their name & email combination; 
    // and (2) this customer has a valid ID by generating a unique ID. 
    // Do nothing if the artist is already on the list.Do nothing if this customer is already on the list.
    //returns customerID.
    int Gallery::addCustomer(NS_ARTGALLERY::Customer customer) { /* PASSED */
        if (customer.getID() < 0) {
            customer.setID(NS_ARTGALLERY::uniqueIDs::next_customerID());
        }
        if (!isAvailable(customer, customersList)) {
            customersList.push_back(customer);
            return customer.getID();
        }
        return customer.getID();
    }


    // artwork curation: 
    // curate a new piece of artwork for the gallery. 
    // newItem.ID, newItem.artistID, and artist.ID are all set to -1 (not available) initially. 
    // As a result, you'll need to assign this newItem a unique ID. 
    // Check if the artist is already on the artistsList using their name and email. 
    // If new, assign this artist a unique ID and add them to the artistList. 
    // If not new, retrieve their ID from the artistList. 
    // You will also need to update the artworkListCurated and the artworkListForSale. 
    // Finally, you will need to update the curationRecords to include this new curation.
    void Gallery::curateArtwork(NS_ARTGALLERY::Artwork newItem, NS_ARTGALLERY::Artist artist) {
       newItem.setID(NS_ARTGALLERY::uniqueIDs::next_artworkID());
        int resultID = getArtistID(artist.getName(), artist.getEmail());
        if (resultID == -1) {
            artist.setID(NS_ARTGALLERY::uniqueIDs::next_artistID());
            newItem.setArtistID(artist.getID());
            artistsList.push_back(artist);
        }
        else {
            newItem.setArtistID(resultID);
        }

        NS_ARTGALLERY::Curation curation{newItem.getID(), newItem.getArtistID(), NS_ARTGALLERY::getTodaysDate()};
        artworksCurated.push_back(newItem);
        artworksForSale.push_back(newItem);
        addCuration(curation);
    }

    // artwork sale: sell a for-sale artwork to a customer. 
    // customer.ID is set to -1 initially. 
    // So you will need to find out if this customer is new using their name and email address. 
    // If new, assign this customer a unique ID and add them to the customerList. 
    // If not, retrieve their ID from customerList. 
    // You will also need to check if the specified artworkID is still for sale. 
    // If yes, update the artworkListForSale by removing this artwork that was just sold, 
    // and update the salesRecords to include this new sale. If this artwork is not for sale, do nothing. 
    void Gallery::sellArtwork(int artworkID, NS_ARTGALLERY::Customer customer) {
       int resultCustomerID = getCustomerID(customer.getName(), customer.getEmail());
       if(resultCustomerID == -1){
          customer.setID(NS_ARTGALLERY::uniqueIDs::next_customerID());
          customersList.push_back(customer);
       }else {
          resultCustomerID = customer.getID();
       }
       
       for(unsigned long int i = 0; i < artworksForSale.size(); i++){
          if(artworkID == artworksForSale[i].getID()){
             artworksForSale.erase(artworksForSale.begin() + i);
             Sale sale{resultCustomerID, artworkID, NS_ARTGALLERY::getTodaysDate()};
             addSale(sale);
          }
       }
    }

    // Accessors

    //returns the unique ID of a gallery
    int Gallery::getID() const {
        return this->ID;
    }

    //returns the name of a gallery
    std::string Gallery::getName() const {
        return this->name;
    }

    //returns the address of a gallery
    std::string Gallery::getAddress() const {
        return this->address;
    }

    //returns the webURL of a gallery
    std::string Gallery::getWebURL() const {
        return this->webURL;
    }

    //returns the size of artistsList
    unsigned long Gallery::num_artists() const {
        return artistsList.size();
    }

    //returns the size of artworksCurated;
    unsigned long Gallery::num_artworksCurated() const {
        return artworksCurated.size();
    }

    //returns the size of artworksForSale;
    unsigned long Gallery::num_artworksForSale() const {
        return artworksForSale.size();
    }

    //returns the size of customersList
    unsigned long Gallery::num_customers() const {
        return customersList.size();
    }

    //returns the size of curationRecords
    unsigned long Gallery::num_curations() const {
        return curationsRecords.size();
    }

    //returns the size of salesRecords
    unsigned long Gallery::num_sales() const {
        return salesRecords.size();
    }

    // retrieves an artist's ID from the artistList using the provided name and email.
    // We assume that name & email can uniquely identify an artist.
    // returns the ID if found; -1 if not. The latter means that this is a new artist.
    int Gallery::getArtistID(string name, string email) const { /* PASSED */
        for (unsigned long int i = 0; i < artistsList.size(); i++) {
            if ((artistsList[i].getName() == name) && (artistsList[i].getEmail() == email)) {
                return artistsList[i].getID();
                break;
            }
        }
        return -1;
    }

    // retrieves a customer's ID from the customerList using the provided name and email.
    // We assume that name & email can uniquely identify a customer.
    // returns the customer's ID if found; -1 if not. The latter means that this is a new customer.
    int Gallery::getCustomerID(std::string name, std::string email) const { /* PASSED */
        for (unsigned long int i = 0; i < customersList.size(); i++) {
            if ((customersList[i].getName() == name) && (customersList[i].getEmail() == email)) {
                return customersList[i].getID();
                break;
            }
        }
        return -1;
    }

    // returns the IDs of for-sale artworks
    vector<int> Gallery::getIDsOfArtworksForSale() const {
        std::vector<int> forSaleArtworkIds;
        for (unsigned long int i = 0; i < artworksForSale.size(); i++) {
            forSaleArtworkIds.push_back(artworksForSale[i].getID());
        }
        return forSaleArtworkIds;
    }

    // returns the unique IDs of the artists who have artworks for sale
    // Note: make sure that you deduplicate the IDs as one artist may have multiple artworks for sale
    vector<int> Gallery::getIDsOfArtistsForSale() const {
        std::vector<int> artistsIDsForSale;
        for (unsigned long int i = 0; i < artworksForSale.size(); i++) {
            artistsIDsForSale.push_back(artworksForSale[i].getArtistID());
        }
        return artistsIDsForSale;
    }

    // Summarize a gallery's curated artworks 
    // (i.e., artworkListCurated) by  art type, style, and subject.
    // ReportType is an enum class declared in the util_date_uniqueIDs.h. 
    // It consists of{artType, artStyle, artSubject}.
    // For example, if reportType is ReportType::artType, 
    // this function will return a vector of the following pairs 
    // : ("ArtType::painting", #), 
    // ("ArtType::photography", #), ("ArtType::drawing", #), ("ArtType::sculpture", #), ("ArtType::other", #).
        // You can call the string toStr_ArtType( ArtType ) function to convert an ArtType value to a string.
    // You algorithm is going to replace the # with the actual number of artworks of the corresponding artType.
    vector<pair<string, int>> Gallery::genArtworksReport(ReportType reportType) {
        // painting, photography, drawing, sculpture, other

        // fineArt, abstract, modern, popArt, other

        // nature, portrait, animal, cartoon, other

        std::vector<pair<string, int>> pairs;

        int painting{0};
        int photography{0};
        int drawing{0};
        int sculpture{sculpture};
        int other{0};
        if (reportType == ReportType::artType) {
            // painting, photography, drawing, sculpture, other
            for (const Artwork& artwork : artworksCurated) {
                switch (artwork.getType()) {
                case ArtType::painting:
                    ++painting;
                    break;
                case ArtType::photography:
                    ++photography;
                    break;
                case ArtType::drawing:
                    ++drawing;
                    break;
                case ArtType::sculpture:
                    ++sculpture;
                    break;
                case ArtType::other:
                    ++other;
                    break;
                }
            }
            pair<string, int> paintingPair{toStr_ArtType(ArtType::painting), painting};
            pair<string, int> photographyPair{toStr_ArtType(ArtType::photography), photography};
            pair<string, int> drawingPair{toStr_ArtType(ArtType::drawing), drawing};
            pair<string, int> sculpturePair{toStr_ArtType(ArtType::sculpture), sculpture};
            pair<string, int> otherPair{toStr_ArtType(ArtType::other), other};

            pairs.push_back(paintingPair);
            pairs.push_back(photographyPair);
            pairs.push_back(drawingPair);
            pairs.push_back(sculpturePair);
            pairs.push_back(otherPair);
        }
        else if (reportType == ReportType::artStyle) {
            // fineArt, abstract, modern, popArt, other
            int fineArt{0};
            int abstract{0};
            int modern{0};
            int popArt{0};
            int other{0};
            for (const Artwork& artwork : artworksCurated) {
                switch (artwork.getStyle()) {
                case ArtStyle::fineArt:
                    ++fineArt;
                    break;
                case ArtStyle::abstract:
                    ++abstract;
                    break;
                case ArtStyle::modern:
                    ++modern;
                    break;
                case ArtStyle::popArt:
                    ++popArt;
                    break;
                case ArtStyle::other:
                    ++other;
                    break;
                }
            }
            pair<string, int> fineArtPair{toStr_ArtStyle(ArtStyle::fineArt), fineArt};
            pair<string, int> abstractPair{toStr_ArtStyle(ArtStyle::abstract), abstract};
            pair<string, int> modernPair{toStr_ArtStyle(ArtStyle::modern), modern};
            pair<string, int> popArtPair{toStr_ArtStyle(ArtStyle::popArt), popArt};
            pair<string, int> otherPair{toStr_ArtStyle(ArtStyle::other), other};

            pairs.push_back(fineArtPair);
            pairs.push_back(abstractPair);
            pairs.push_back(modernPair);
            pairs.push_back(popArtPair);
            pairs.push_back(otherPair);
        }
        else {
            // nature, portrait, animal, cartoon, other
            int nature{0};
            int portrait{0};
            int animal{0};
            int cartoon{0};
            int other{0};
            
            for (const Artwork& artwork : artworksCurated) {
                switch (artwork.getSubject()) {
                case ArtSubject::nature:
                    ++nature;
                    break;
                case ArtSubject::portrait:
                    ++portrait;
                    break;
                case ArtSubject::animal:
                    ++animal;
                    break;
                case ArtSubject::cartoon:
                    ++cartoon;
                    break;
                case ArtSubject::other:
                    ++other;
                    break;
                }
            }

            pair<string, int> naturePair{toStr_ArtSubject(ArtSubject::nature), nature};
            pair<string, int> portraitPair{toStr_ArtSubject(ArtSubject::portrait), portrait};
            pair<string, int> animalPair{toStr_ArtSubject(ArtSubject::animal), animal};
            pair<string, int> cartoonPair{toStr_ArtSubject(ArtSubject::cartoon), cartoon};
            pair<string, int> otherPair{toStr_ArtSubject(ArtSubject::other), other};

            pairs.push_back(naturePair);
            pairs.push_back(portraitPair);
            pairs.push_back(animalPair);
            pairs.push_back(cartoonPair);
            pairs.push_back(otherPair);
        }

        return pairs;
    }

    // add a new curation record to curationRecords.
    void Gallery::addCuration(NS_ARTGALLERY::Curation curation) {
        curationsRecords.push_back(curation);
    }

    // add a new sale record to salesRecords
    void Gallery::addSale(NS_ARTGALLERY::Sale sale) {
        salesRecords.push_back(sale);
    }
    /***** End of Gallery functions implementation *****/

}//end of NS_ARTGALLERY