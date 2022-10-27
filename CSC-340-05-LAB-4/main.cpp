//  main.cpp
//  ArtGallerySimplified
//
//created by [Robel K Ayelew]
//date: 

#include <iostream>
#include "util_date_uniqueIDs.h"
#include "unitTests.h"

//please feel free to create a text-based user interface to manage an art gallery 

int main() {
    using namespace NS_ARTGALLERY;
    using namespace NS_UTESTS;
    
    test_Artwork();
    test_set_getStyle_Artwork();
    test_setDimension_Artwork();
    test_Artist();
    test_set_getID_Artist();
    test_Customer2();
    test_set_getName_Customer();
    test_Curation2();
    test_set_getDate_Curation();
    test_Sale2();
    test_set_getCustomerID_Sale();
    test_getArtistID_Gallery();
    test_getCustomerID_Gallery();
    test_getIDsOfArtistsForSale_Gallery();
    test_getIDsOfArtworksForSale_Gallery();
    test_genArtworksReport_artType_Gallery();
    test_curateArtwork_Gallery();
    test_sellArtwork_Gallery(); 
   
   

    return 0;
}
