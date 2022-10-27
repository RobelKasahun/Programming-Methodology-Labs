//
//  DesignDoc.h
//  ArtGallerySimplified
//
//

/* This Document is fully commented. As such, its content will be
 ignored by the compiler.
 ***************************
Please check the full DesignDoc included in the project description.

 Your to-do #1:  describe your algorithm in pseudo code for the following data operation in the Gallery class:
    - curateArtwork(Artwork newItem, Artist artist); //artwork curation: curate a new piece of artwork for the gallery. newItem.ID and artist.ID are set to -1 (not available) initially. As a result, you'll need to assign this newItem a unique ID. Check if the artist is already on the artistList using their name and email. If new, assign this artist a unique ID and add them to the artistList. if not new, retrieve their ID from the artistList. You will also need to update the artworkListCurated and the artworkListForSale. Finally, you will need to update the curationRecords to include this new curation.
         - Assign unique id to artwork's ID
         - Check if the artist is available in artistsList
            - if does not exist
               - assign artist ID a unique ID
               - assign artist.getID() to artwork's artistID
               - and add the artist to the artistsList
            - Otherwise
               - get the id of the artist.

   - Create a curation object that has artwork ID, artwork's artistID, and today's date.
   - add the arwork to artworksCurated.
   - add the artwork to artworksForSale.
   - and add the curation object to addCuration.

 Your to-do #2:  describe your algorithm in pseudo code for the following data operation in the Gallery class:
    - sellArtwork(int artworkID, Customer customer); //artwork sale: sell a for-sale artwork to a customer. customer.ID is set to -1 initially. So you will need to find out if this customer is new or not using their name and email address. If new, assign this customer a unique ID and add them to the customerList. If not, retrieve their ID from customerList. You will also need to check if the specified artworkID is still for sale. If yes, update the artworkListForSale by removing this artwork that was just sold, and update the salesRecords to include this new sale.

   - Check the customer in the customersList
   - if the customer does not exist in the customersList
      - assign the customer a unique id
      - add the customer to the customersList
   - Otherwise
      - check if the artwork is for sale
         - if so
            - erase the artwork
            - and add the artwork to the salesRecords

 Your to-do #3:  describe your algorithm in pseudo code for the following data operation in the Gallery class:
     - genArtworksReport( ReportType reportType); //summarize a gallery's curated artworks by their type, style, and subject. ReportType is an enum class that consists of {artType, artStyle, artSubject}.  For example, if reportType is ReportType::artType, your summary will consist of the following pairs: (ArtType::painting, #), (ArtType::photography, #), (ArtType::drawing, #), (ArtType::sculpture, #), (ArtType::other, #). Here, ArtType is another user-defined enum class. You algorithm is going to replace the # with the actual number of artworks of the corresponding artType.
     
   - if the reportType is artType 
      - count the number of painting, photography, drawing, sculpture, other, and add them to vector of pair<string, int> and return the vector.
   - else if reportType is artStyle
      - count the number of fineArt, abstract, modern, popArt, other, and add them to vector of pair<string, int> and return the vector.
   - else
      - count the number of nature, portrait, animal, cartoon, other, and add them to vector of pair<string, int> and return the vector.

** End-of-DesignDoc_h */