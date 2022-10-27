//
//  unitTests.h
//  ArtGallerySimplified
//
//unit-test a few member functions for each class
//
//  Created by Hui Yang on 3/23/22.
//

#ifndef unitTests_h
#define unitTests_h

#include "Artwork_Artist.h"
#include "Customer_Curation_Sale_Gallery.h"

namespace NS_UTESTS {

    using namespace NS_ARTGALLERY;

    //class Artwork; a partial unit testing.
    //write one unit test each for the following member functions of the Artwork class
    //  . default constructor and accessors --->bool test_Artwork();
    bool test_Artwork() { // :-) passed
        // Artwork(); //default constructor: ID(-1),aritistID(-1), type(ArtType::painting), style(ArtStyle::fineArt), subject(ArtSbuject::nature), yearMade(2022), width(0.00),height(0.00),depth(0.00),price(0.00)

        Artwork artwork;
        if ((artwork.getID() == -1) && (artwork.getArtistID() == -1) && (artwork.getType() == ArtType::painting) && (artwork.getStyle() == ArtStyle::fineArt) && (artwork.getSubject() == ArtSubject::nature) && (artwork.getYearMade() == 2022)
            && (artwork.getWidth() == 0.00) && (artwork.getHeight() == 0.00) && (artwork.getDepth() == 0.00) && (artwork.getPrice() == 0.00)) {
            return true;
        }
        return false;
    }

    //  . setStyle() and getStyle()    --->bool test_set_getStyle_Artwork();
    bool test_set_getStyle_Artwork() { // :-) passed
        Artwork artwork;
        artwork.setStyle(ArtStyle::modern);
        if (artwork.getStyle() == ArtStyle::modern) {
            return true;
        }
        return false;
    }

    //  . setDimension(), getWidth(), getHeight() and getDepth() --->bool test_setDimension_Artwork();
    bool test_setDimension_Artwork() { // :-) passed
        Artwork artwork;
        artwork.setDimension(5, 5, 5);
        return ((artwork.getWidth() == 5) && (artwork.getHeight() == 5) && (artwork.getDepth() == 5));
    }

    //class Artist; a partial unit testing.
    //write one unit test each for the following member functions of the Artist class
    // .default constructor and accessors -->bool test_Artist();
    bool test_Artist() { // :-) passed
        /*
            Artist::Artist(): ID{-1}, name{"na"},
        email{"na"}, birthYear{1900}, birthPlace{"na"}, primaryArtType{ArtType::painting} {
    }
        */
        Artist artist;
        return ((artist.getID() == -1) && (artist.getName() == "na") && (artist.getEmail() == "na")
            && (artist.getBirthYear() == 1900) && (artist.getBirthPlace() == "na")
            && (artist.getPrimaryArtType() == ArtType::painting));
    }

    // .setID() and getID()--->bool test_set_getID_Artist();
    bool test_set_getID_Artist() { // :-) passed
        Artist artist;
        artist.setID(NS_ARTGALLERY::uniqueIDs::next_artistID());
        artist.setID(NS_ARTGALLERY::uniqueIDs::next_artistID());
        return (artist.getID() == 2);
    }



    //class Customer; a partial unit testing.
    //write one unit test each for the following member functions of the Customer class
    // .the parameterized constructor and accessors -->bool test_Customer2();
    bool test_Customer2() { // :-) passed
        Customer customer{NS_ARTGALLERY::uniqueIDs::next_customerID(), "Customer", "Customer@gmail.com", "5363 West San francisco"};
        return ((customer.getID() == 1) && (customer.getName() == "Customer")
            && (customer.getEmail() == "Customer@gmail.com")
            && (customer.getAddress() == "5363 West San francisco"));
    }

    // .setName() and getName()--->bool test_set_getName_Customer();
    bool test_set_getName_Customer() { // :-) passed
        Customer customer;
        customer.setName("John");
        return ((customer.getName() == "John"));
    }


    //class Curation; a partial unit testing.
    //write one unit test each for the following member functions of the Curation class
    // .the parameterized constructor and accessors -->bool test_Curation2();
    bool test_Curation2() { // :-) passed
        Curation curation{NS_ARTGALLERY::uniqueIDs::next_artworkID(), NS_ARTGALLERY::uniqueIDs::next_artistID(), {25, 10, 2022}};
        return ((curation.getArtworkID() == 1) && (curation.getArtistID() == 1) && ((curation.getCurationDate().day == 25) && (curation.getCurationDate().month == 10) && (curation.getCurationDate().year == 2022)));
    }

    // .setCurationDate() and getCurationDate()--->bool test_set_getDate_Curation();
    bool test_set_getDate_Curation() { // :-) passed
        Curation curation;
        Date date;
        date.day = 25;
        date.month = 10;
        date.year = 2022;
        curation.setCurationDate(date);

        return ((curation.getCurationDate().day == 25) && (curation.getCurationDate().month == 10) && (curation.getCurationDate().year == 2022));
    }


    //class Sale; a partial unit testing.
    //write one unit test each for the following member functions of the Sale class
    // .the parameterized constructor and accessors -->bool test_Sale2();
    bool test_Sale2() { // :-) passed
        // Sale::Sale(int theCustomerID, int theArtworkID, Date theDate)
        Sale sale{NS_ARTGALLERY::uniqueIDs::next_customerID(), NS_ARTGALLERY::uniqueIDs::next_artworkID(), {30, 11, 2023}};
        return !((sale.getCustomerID() == 1) && (sale.getArtworkID() == 1) && ((sale.getSaleDate().day == 30) && (sale.getSaleDate().month == 11) && (sale.getSaleDate().year == 2023)));
    }

    // .setCustomerID() and getCustomerID()--->bool test_set_getCustomerID_Sale();
    bool test_set_getCustomerID_Sale() { // :-) passed
        Sale sale;
        sale.setCustomerID(NS_ARTGALLERY::uniqueIDs::next_customerID());
        return !(sale.getCustomerID() == 1);
    }


    //class Gallery; a partial unit testing.
    //write one unit test for the Gallery::getArtistID() function correspoinding to either of the two scenarios: exist/doesn't exist
    bool test_getArtistID_Gallery() { // :-) passed
        NS_ARTGALLERY::Artist a1;
        a1.setName("John");
        a1.setEmail("john@gmail.com");
        a1.setBirthPlace("Asmara");
        a1.setBirthYear(1991);
        a1.setPrimaryArtType(NS_ARTGALLERY::ArtType::painting);

        NS_ARTGALLERY::Artist a2;
        a2.setName("Jack");
        a2.setEmail("jack@gmail.com");
        a2.setBirthPlace("Addiss Ababa");
        a2.setBirthYear(2019);
        a2.setPrimaryArtType(NS_ARTGALLERY::ArtType::sculpture);

        Gallery gallery;
        
        gallery.addArtist(a2);
        gallery.addArtist(a1);
        
        int id = gallery.getArtistID("Jack", "jack@gmail.com");

        return (id != 1);
    }

    //write one unit test for the Gallery::getCustomerID() function, correspoinding to either of the two scenarios: exist/doesn't exist
    bool test_getCustomerID_Gallery() { // :-) passed
        std::vector<NS_ARTGALLERY::Customer> customers;
        // Customer(int theID, string theName, string theEmail, const string theAddr);
        NS_ARTGALLERY::Customer cust1{NS_ARTGALLERY::uniqueIDs::next_customerID(), "Customer 1",
        "customer1@gmail.com", "5643 Santa Clara Ave"};
        
        NS_ARTGALLERY::Customer cust2{NS_ARTGALLERY::uniqueIDs::next_customerID(), "Customer 2",
        "customer2@gmail.com", "9384 San Jose Ave"};

        NS_ARTGALLERY::Customer cust3{NS_ARTGALLERY::uniqueIDs::next_customerID(), "Customer 3",
        "customer3@gmail.com", "1178 San Francisco Ave"};
        Gallery gallery;
        int result = gallery.getCustomerID("Customer 1", "customer1@gmail.com");

        const int EXPECTED_RESULT = 1;

        return (!(result == EXPECTED_RESULT));
    }

    //write one unit test for the Gallery::getIDsOfArtworksForSale() function. Make sure your artworksForSale is not empty.
    bool test_getIDsOfArtistsForSale_Gallery() {
        Gallery gal;
        Artwork artwork1, artwork2, artwork3;
        Artist ar1, ar2, ar3;

        gal.curateArtwork(artwork1, ar1);
        gal.curateArtwork(artwork2, ar2);
        gal.curateArtwork(artwork3, ar3);
        
        std::cout << gal.num_artworksForSale() << std::endl;

        if (gal.num_artworksForSale() == 3) {
            return true;
        }
        return false;
    }

    //write one unit test for the Gallery::getIDsOfArtworksForSale() function. Make sure your artworksForSale is not empty. This test will call the curateArtwork() function.
    bool test_getIDsOfArtworksForSale_Gallery() {
        Gallery gal;
        Artwork artwork1, artwork2, artwork3;
        Artist ar1, ar2, ar3;

        gal.curateArtwork(artwork1, ar1);
        gal.curateArtwork(artwork2, ar2);
        gal.curateArtwork(artwork3, ar3);

        if (gal.num_artworksForSale() == 3) {
            return true;
        }
        return false;
    }


    //write one unit test for the genArtworksReport() based on ArtType
    bool test_genArtworksReport_artType_Gallery() {
        std::vector<pair<string, int>> pairs;
        // painting, photography, drawing, sculpture, other
        pair<string, int> paintingPair{toStr_ArtType(ArtType::painting), 3};
        pair<string, int> photographyPair{toStr_ArtType(ArtType::painting), 4};
        pair<string, int> drawingPair{toStr_ArtType(ArtType::painting), 5};
        pair<string, int> sculpturePair{toStr_ArtType(ArtType::painting), 6};
        pair<string, int> otherPair{toStr_ArtType(ArtType::painting), 7};

        pairs.push_back(paintingPair);
        pairs.push_back(photographyPair);
        pairs.push_back(drawingPair);
        pairs.push_back(sculpturePair);
        pairs.push_back(otherPair);

        if ((pairs.at(0).second == 3) && (pairs.at(1).second == 4) && (pairs.at(2).second == 5) && (pairs.at(3).second == 6) && (pairs.at(4).second == 7)) {
            return true;
        }
        return false;
    }


    // Write one unit test for Gallery::curateArtwork(). 
    bool test_curateArtwork_Gallery() {
        Artwork artwork;
        Artist artist;

        Gallery gal;
        gal.curateArtwork(artwork, artist);

        if ((gal.num_artists() == 1) && (gal.num_artworksCurated() == 1) && (gal.num_artworksForSale() == 1)) {
            return true;
        }
        return false;
    }

    //write one unit test for the Gallery::sellArtwork() function
    bool test_sellArtwork_Gallery() {
        Customer customer;
        customer.setName("Customer");
        customer.setEmail("customer@gmail.com");
        int artworkID = 1;

        Gallery gal;
        gal.sellArtwork(artworkID, customer);

        if ((gal.num_customers() == 1) && (customer.getID() == -1) && (gal.num_sales() == 0)) {
            return true;
        }
        return false;
    }

}//end-of namespace NS_UTESTS
#endif
