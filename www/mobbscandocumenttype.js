/*global cordova, module*/
/**
 * Enum for type of documents that can be scanned.
 * @readonly
 * @enum {string}
 * @memberof MobbScanAPI
 */
var MobbScanDocumentType = {
    /** TD1 sized ID card with MRZ-only recognition. (ICAO Doc 9303. First revision: 1996). */
    TD1IDCard: { value: "TD1IDCard" },
    /** Spanish national identity card, version ESP-BO-02002 (Date Issued: 03.12.2001). */
    ESPIDCardV1: { value: "ESPIDCardV1" },
    /** Spanish national identity card, version ESP-BO-05001 (Date Issued: 02.01.2015). */
    ESPIDCardV2: { value: "ESPIDCardV2" },
    /** Spanish national identity card, version ESP-BO-05001 (Date Issued: 02.01.2015). */
    ESPIDCardV3: { value: "ESPIDCardV3" },
    /** Default Spanish national identity card. */
    ESPIDCard: { value: "ESPIDCard" },
    /** NIE (Número de Identificación de Extranjero), identification number assigned by the Spanish authorities to any foreigner, version ESP-HO-02002 (Date Issued: 10.05.2010). */
    NIE: { value: "NIE" },
    /** Passport card with TD3 size. */
    PASSPORT_TD3: { value: "PASSPORT_TD3" },
    /** Switzerland national identity card (Date Issued: 11.2005). */
    CHEIDCard: { value: "CHEIDCard" },
    /** UK identity card (Date Issued:). */
    GBRIDCard: { value: "GBRIDCard" },
    /** Croatia national identity card (Date Issued:06.2015). */
    HRVIDCard: { value: "HRVIDCard" },
    /** Italy national identity card (Date Issued:01.2004). */
    ITAIDCard: { value: "ITAIDCard" },
    /** Bulgaria national identity card (Date Issued:03.2010). */
    BGRIDCard: { value: "BGRIDCard" },
    /** Hungary national identity card (Date Issued:01.2016). */
    HUNIDCard: { value: "HUNIDCard" },
    /** Poland national identity card (Date Issued:03.2015). */
    POLIDCard: { value: "POLIDCard" },
    /** Romania national identity card (Date Issued: 01.2017). */
    ROUIDCard: { value: "ROUIDCard" },
    /** Deutschland default national identity card. */
    DEUIDCard: { value: "DEUIDCard" },
    /** Deutschland foreign identity card, (Date Issued: 09.2011). */
    DEUIDCardAF: { value: "DEUIDCardAF" },
    /** Deutschland national identity card, version 2 (Date Issued: 11.2001). */
    DEUIDCardV1: { value: "DEUIDCardV1" },
    /** Deutschland national identity card, last version released (Date Issued: 01.11.2010). */
    DEUIDCardV2: { value: "DEUIDCardV2" },
    /** Passport of Kuwait. */
    KWTPassport: { value: "KWTPassport" },
    /** Mexico default national identity card. */
    MEXIDCard: { value: "MEXIDCard" },
    /** Mexico national identity card, version C (Date Issued: 09.2008). */
    MEXIDCardC: { value: "MEXIDCardC" },
    /** Mexico national identity card, version D (Date Issued: 25.11.2013). */
    MEXIDCardD: { value: "MEXIDCardD" },
    /** Mexico national identity card, version E (Date Issued: 06.2014). */
    MEXIDCardE: { value: "MEXIDCardE" },
    /** El Salvador national identity card, version 1 (Date Issued: 01.11.2001). */
    SLVIDCardV1: { value: "SLVIDCardV1" },
    /** El Salvador residence permit. */
    SLVIDCardCA4: { value: "SLVIDCardCA4" },
    /** Colombian national identity card, version 3 (Date Issued: 01.05.2000). */
    COLIDCardV3: { value: "COLIDCardV3" },
    /** Chilean national identity card, electronic version (Date Issued: 02.09.2013). */
    CHLIDCardE: { value: "CHLIDCardE" },
    /** Peruvian national identity card, version 1 (Date Issued: 1997). */
    PERIDCardV1: { value: "PERIDCardV1" },
    /** Portuguese national identity card. */
    PRTIDCard: { value: "PRTIDCard" },
    /** Other id card not supported on mobbscan */
    OTHIDCard: { value: "OTHIDCard" },
    /** Other passport not supported on mobbscan */
    OTHPassport: { value: "OTHPassport" },
    /** Unknow document no supported on mobbscan */
    UNKNOWN: { value: "UNKNOWN" },
    /** Passport of United Arab Emirates. */
    AREPassport: { value: "AREPassport" },
    /** Passport of China. */
    CHNPassport: { value: "CHNPassport" },
    /** Passport of Austria. */
    AUTPassport: { value: "AUTPassport" },
    /** Austrian  national identity card. */
    AUTIDCard: { value: "AUTIDCard" },
    /** Passport of Saudi Arabia. */
    SAUPassport: { value: "SAUPassport" },
    /** Passport of Ukraine. */
    UKRPassport: { value: "UKRPassport" },
    /** Passport of United States of America. */
    USAPassport: { value: "USAPassport" }
};

module.exports = MobbScanDocumentType;
