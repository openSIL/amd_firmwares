/*****************************************************************************
*
* Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
*
*******************************************************************************
*/
/* ----------------------------------------------------------------------------
 *
 * @file bl_syscall.h
 *
 * @brief Defines the SVC Interface APIs.
 *
 * @details SVC API Interface description for User Space Applications.
 *
 *
 * ----------------------------------------------------------------------------
 */

/*! \file */

#ifndef BL_SYSCALL_H
#define BL_SYSCALL_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "bl_errorcodes.h"

/** @def PSP_BL_SVC_IF_VER
* PSP BootLoader Interface version 1.0
*/
#define PSP_BL_SVC_IF_VER "1.0"

#define SVC_EXIT                            0x00
#define SVC_MAP_USER_STACK                  0x01
#define SVC_LOAD_BINARY                     0x02
#define SVC_MAP_SMN_ON_DIE_NUM              0x03
#define SVC_MAP_SMN_ON_CURRENT_DIE          0x04
#define SVC_UNMAP_SMN                       0x05
#define SVC_DEBUG_PRINT                     0x06
#define SVC_MAP_SYSHUB                      0x07
#define SVC_UNMAP_SYSHUB                    0x08
#define SVC_READ_SYSHUB                     0x09
#define SVC_WRITE_SYSHUB                    0x0A
#define SVC_SHA256                          0x0B
#define SVC_MODEXP                          0x0C
#define SVC_RSAPSS_VERIFY                   0x0D
#define SVC_AES_ECB_ENCRYPT                 0x0E
#define SVC_SHA256_OTP                      0x0F
#define SVC_GET_MCM_INFO                    0x10
#define SVC_MASTER_BROACAST                 0x13
#define SVC_SLAVE_GET_BROACAST_DATA         0x14
#define SVC_SEARCH_BIOS_DIR                 0x16
#define SVC_GET_DATA_FROM_SLAVES            0x17
#define SVC_SEND_DATA_TO_MASTER             0x18
#define SVC_SET_DEBUG_STATE                 0x19
#define SVC_DEBUG_PRINT_EX                  0x1A
#define SVC_WAIT_10NS_MULTIPLE              0x1B
#define SVC_GET_BOOT_MODE                   0x1C
#define SVC_OTP_HMAC256_SIGN                0x1D
#define SVC_SPILOAD_VALIDATE_HMAC256_APOB   0x1E
#define SVC_PROGRAM_UMC_KEYS                0x21
#define SVC_MCM_SYNC_ON_DATA                0x24
#define SVC_MAP_SYSHUB_EX                   0x25
#define SVC_READ_SYSHUB_EX                  0x26
#define SVC_WRITE_SYSHUB_EX                 0x27
#define SVC_SEND_PSP_SMU_MSG                0x28
#define SVC_SET_RESERVED_DRAM               0x2A
#define SVC_GMI_NON_FUNCTIONAL              0x2C
#define SVC_LOAD_FW_IMAGE_BY_INSTANCE       0x2D
#define SVC_DELAY_IN_MICRO_SECONDS          0x2F
#define SVC_GMI_NONCE_KEY_PROGRAM           0x30
#define SVC_AES_GENERIC                     0x36
#define SVC_CACHE_OPERATION                 0x37
#define SVC_TRNG                            0x39
#define SVC_SET_MIN_SEV_ASID                0x3A
#define SVC_LOAD_BINARY_FROM_SUBTYPE        0x3D
#define SVC_SLAVE_UNLOCK_REQUEST            0x40
#define SVC_GET_CUK                         0x42
#define SVC_SEARCH_BIOS_DIR_V2              0x43
#define SVC_GET_SMM_RANGE                   0x48
#define SVC_SET_PSP_DEBUG_MODE              0x4A
#define SVC_SET_SYSHUB_WDTTIMER_INTERVAL    0x4C
#define SVC_LOAD_BINARY_BY_ATTRIB           0x4D
#define SVC_MCA_RESET_MBAT_ENTRY            0x4E
#define SVC_MAP_SMN_WITH_SIZE               0x50
#define SVC_UNMAP_SMN_WITH_SIZE             0x51
#define SVC_SHA                             0x55
#define SVC_GET_PSP_VERSION                 0x58
#define SVC_GETSET_SYS_PROP                 0x5B
#define SVC_READ_HARVEST_FUSE               0x5C
#define SVC_MAP_SYSHUB_GENERIC              0x5D
#define SVC_P2P_EXCHANGE_DATA_WITH_SLAVES   0x5E
#define SVC_DTPM_CONFIG                     0x63
#define SVC_SEND_CMD_TO_MPIO                0x65
#define SVC_P2P_SYNC_ON                     0x68
#define SVC_P2P_SEND_CMD                    0x69
#define SVC_P2P_WAIT_FOR_CMD                0x6A
#define SVC_P2P_SEND_RESPONSE               0x6B
#define SVC_P2P_WAIT_FOR_RESP               0x6C
#define SVC_HMAC256_SIGN_VALIDATE           0x6E    // Change this SVC Cmd to SVC_HMAC256_SIGN_VALIDATE 0x33 to be in sync with client.
#define SVC_MCA_GET_MASTER_THREAD_COUNT     0X78
#define SVC_MCA_WRITE_MBAT_IN_S3_AREA       0x79
#define SVC_MCA_SET_MBAT_OFFSET             0X7A
#define SVC_DECOMPRESS_ZLIB_BINARY          0x7B

#define SVC_GET_CONFIG                      0xAA
#define SVC_SET_CONFIG                      0xA9
#define SVC_DISABLE_PSB_AUTOFUSE            0xB4
#define SVC_UNLOAD_BINARY                   0xBC



// Define node_list die type codes
typedef enum SOC_DIE_TYPE_E {
    DIE_TYPE_CPU  = 0,
    DIE_TYPE_APU  = 1,
    DIE_TYPE_DGPU = 2,
} SOC_DIE_TYPE;

#define FCH_IO_BASE_ADDRESS       (0xFFFFFFFDFC000000ull)
// Post code address (IO port 80)
#define POSTCODEADDR                                   (FCH_IO_BASE_ADDRESS + 0x80)

typedef enum SVC_CONFIG_ID_E {
    SVC_CONFIG_ID_RESERVED                      = 0x00,
    SVC_CONFIG_ID_TRACELOG_DISABLE              = 0x26,
    SVC_CONFIG_ID_SET_APIC_16T_MODE             = 0x33,
    SVC_CONFIG_ID_SET_S3_MCA_CONTROL            = 0x41,
    SVC_CONFIG_ID_SFS_SUPPORT                   = 0x46,
    SVC_CONFIG_ID_SFS_OEM_CO_SIGN               = 0x47,
    SVC_CONFIG_ID_SET_S3_IPID_OFFSET            = 0x50,
} SVC_CONFIG_ID;

#define UNUSED_VALUE                0xDEADBEEF

#define MAX_TOTAL_DIE_NUM           32
#define FW_SUPPORTED_MAX_NUM_CCDS   16

// Define HMCA Operation types
typedef enum HMAC_OP_TYPE_E {
    HMAC_SIGN_OP = 0,
    HMAC_VALIDATE_OP = 1,
    HMAC_OP_MAX = 2
} HMAC_OP_TYPE;

typedef enum RESERVED_DRAM_MODULE_ID {
    RESERVED_DRAM_MODULE_PSP,
    RESERVED_DRAM_MODULE_SMU,
    RESERVED_DRAM_MODULE_RAS_EINJ,
    RESERVED_DRAM_MODULE_PSP_UNSECURE_GENERIC,
    RESERVED_DRAM_MODULE_AIED = 8

} RESERVED_DRAM_MODULE_ID;

/**
 * SHA types same as ccp SHA type in crypto.h
 */
typedef enum SHA_TYPE_T {
    SHA_TYPE_256,
    SHA_TYPE_384,
    SHA_TYPE_512
} SHA_TYPE;

// All SHA operation supported
typedef enum SHA_OPERATION_MODE {
    SHA,
    SHA_OTP,
    SHA_HMAC,
    SHA_GENERIC,
    SHA_OPERATION_MAX_VAL = SHA_GENERIC
} SHA_OPERATION_MODE;

// SHA Supported Data Structures
typedef struct SHA_GENERIC_DATA_T {
    SHA_TYPE   SHAType;
    uint8_t    *Data;
    size_t     DataLen;
    uint8_t    DataMemType;
    uint8_t    Padding1[3];
    uint8_t    *Digest;
    size_t     DigestLen;
    uint8_t    *IntermediateDigest;
    size_t     IntermediateMsgLen;
    uint8_t    Som;
    uint8_t    Padding2[3];
    uint8_t    Eom;
    uint8_t    Padding3[3];
} SHA_DATA;

typedef struct SHA_OTP_DATA_T {
    SHA_TYPE   SHAType;
    uint8_t    *pHash;
} SHA_OTP_DATA;

typedef struct SHA_HMAC_DATA_T {
    SHA_TYPE   SHAType;
    uint8_t    *pHmac;
    uint32_t   DataSize;
    uint8_t    *pData;
} SHA_HMAC_DATA;

typedef union SHA_OPERATION_T {
    SHA_DATA        SHA;
    SHA_OTP_DATA    SHA_OTP;
    SHA_HMAC_DATA   SHA_HMAC;
} SHA_OPERATION;

typedef struct MPIO_RESP_T {
    uint32_t   resp1;
    uint32_t   resp2;
} MPIO_RESP;

/**
 * Mod Exp parameter structure as services can only pass in 4 parameters
 */
typedef struct MOD_EXP_PARAMS_T {
    char       *pExponent;   // Exponent address
    uint32_t   ExpSize;      // Exponent size in bytes
    char       *pModulus;    // Modulus address
    uint32_t   ModulusSize;  // Modulus size in bytes
    char       *pMessage;    // Message address
    char       *pOuput;      // Output address; Must be big enough to hold the data of ModulusSize
} MOD_EXP_PARAMS;

/**
 * RSA PSS parameter structure as services can only pass in 4 parameters
 */
typedef struct RSAPSS_VERIFY_PARAMS_T {
    char       *pHash;       // Message digest to verify the RSA signature
    uint32_t   HashLen;      // hash length in bytes
    char       *pModulus;    // Modulus address
    uint32_t   ModulusSize;  // Modulus length in bytes
    char       *pExponent;   // Exponent address
    uint32_t   ExpSize;      // Exponent length in bytes
    char       *pSig;        // Signature to be verified, same size as ModulusSize
} RSAPSS_VERIFY_PARAMS;

/**
 * AES ECB parameter structure as services can only pass in 4 parameters
 */
typedef struct AES_ECB_ENCRYPT_PARAMS_T {
    uint32_t   Key;           // Key (either pointer to local memory or LSB number)
    uint32_t   KeyMemType;    // Key memory type
    uint32_t   KeySize;       // Key size in bytes; valid values 16, 24 and 32
    char       *pSrc;         // Source address, must be 16 byte aligned
    uint32_t   SrcMemType;    // Source memory type
    uint32_t   SrcLen;        // Source length, must be non-zero multiple of 16
    char       *pDest;        // Destinateion address, must be 16 byte aligned
    uint32_t   DestMemType;   // Destination memory type
} AES_ECB_ENCRYPT_PARAMS;

typedef struct NODE_LIST_T {
    uint8_t   node_id;     // DF node_id, read from, DF_:SystemCfg.MyNodeId[27:16](master)/c2pmsg_55[15:0](slave)
    uint8_t   die_type;    // DF_:SystemCfg.MyDieType[1:0](master)/c2pmsg_55[17:16](slave) indicating whether Die is CPU, APU or GPU
    uint8_t   hop_count;   // HopCount indicate the distance of each die from local die.
                           // So needed to perform address access over SMN
} NODE_LIST;

/**
 * MCM configuration information to be returned to the caller.
 */
typedef struct MCM_INFO_T {
    uint32_t   psp_bl_version;  // PSP BL version
    uint32_t   prot_version;    // P2P communication protocol version
    uint32_t   num_of_sockets;  // Total number of sockets present in system
    uint32_t   num_of_dies;     // Total number of dies present in system
    // WAFL topology flags:
    // bit 0: if set, the WAFL topology in the wafl node list array is a line
    // bit 1: if set, the wafl node list lists the WAFL nodes in the link1 link0 order
    uint8_t     flags;
    NODE_LIST   node_list[MAX_TOTAL_DIE_NUM];
    uint32_t    current_socket_id;                                       // Current Socket ID
    uint32_t    ccd_present_bit_mask;                                    // Bit mask for CCD Present, 1:CCD Present, 0:CCD not present
    uint16_t    core_present_in_ccd_bit_mask[FW_SUPPORTED_MAX_NUM_CCDS]; // Bit mask for cores present for each CCDs, 1:Core Present, 0: Core not present
    uint64_t    ppin;                                                    // Processor Serial Number
    uint32_t    umc_present_bit_mask;                                    // Bit mask of present UMCs (needed for harvesting)
    uint8_t     ecc_seed_hash[32];                                       // Hash of the ECC SEED value from LSB1
    bool        is_smt_enabled;                                          // Flag to indicate if smt is enabled or not, 1: SMT enabled, 0: SMT not enabled
} MCM_INFO;

typedef enum P2P_SYNC_FW_MODULE_MAJOR_NUM_T {
    P2P_SYNC_FW_MODULE_INVALID   = 0x0,
    P2P_SYNC_FW_MODULE_PSP       = 0x1,
    P2P_SYNC_FW_MODULE_SDU       = 0x2,
    P2P_SYNC_FW_MODULE_ABL       = 0x3,
    P2P_SYNC_FW_MODULE_SEV       = 0x4,
    P2P_SYNC_FW_MODULE_PSP_UAPP  = 0x6,
    P2P_SYNC_FW_MODULE_DRTM      = 0x7,
    P2P_SYNC_FW_MODULE_MAX       = 0x8
} P2P_SYNC_FW_MODULE_MAJOR_NUM;

typedef struct SLAVE_DATA_BUF_T {
    uint8_t    *data;
    uint32_t   size;
    uint32_t   resp;
} SLAVE_DATA_BUF;

typedef struct P2P_DATA_BUF_T {
    uint8_t          cmd_id;
    uint32_t         slave_id;
    bool             continuous_cmd_flag;
    uint8_t          *data;
    uint32_t         size;
    SLAVE_DATA_BUF   *pslave_data;           // If there is not data expected from Slave, then this can be set to NULL.
} P2P_DATA_BUF;

typedef struct DATA_BUF_T {
    uint8_t  *pdata;  // If no response data, then this can be NULL
    uint32_t  size;   // If no response data, then set this to NULL.
                      // Input: indicate size available
                      // Output: On response, PSP FW will update this with size of received data
    uint32_t  status; // If used for response, will hold the response status
                      // if unused, set the value to 0.
} p2p_buf_t;

typedef struct P2P_CMD_STRUCT {
    uint16_t  cmd_id;
    uint8_t   reserved[2];
    p2p_buf_t *pbuf;
    uint32_t  reserved1[2];
} p2p_cmd_t;

typedef struct P2P_RESP_STRUCT {
    uint16_t   cmd_id;
    uint8_t    reserved[2];
    p2p_buf_t  *pbuf;           // response data.
    uint32_t   num_resp_data;   // specify how many resp p2p_buf_t structures pdata points to
    uint32_t   reserved1[2];
} p2p_resp_t;

typedef struct TypeAttrib_t {
    uint32_t   Type           : 8; // Type of BIOS entry 0x60,0x61,0x62
    uint32_t   RegionType     : 8; // 0 - non Secure, 1 - ARM TA1, 2 - ARM TA2, 3 - ARM TMZ, 4 - Reset
    uint32_t   BiosResetImage : 1; // Set for SEC or EL3 fw,
    uint32_t   Copy           : 1; // Set for copy
    uint32_t   ReadOnly       : 1; // 0 - write, 1 - read only
    uint32_t   CompressedZlib : 1; // 0 - no compression, 1 - Zlib compressed
    uint32_t   Instance       : 4; // Specify the instance of an entry
    uint32_t   SubProgram     : 3; // Specify the SubProgram
    uint32_t   Reserved       : 5;
} TypeAttrib; // Type & BIOS_FIRMWARE Attribute field

typedef uint8_t BIOS_DIRECTORY_ENTRY_TYPE;
typedef TypeAttrib BIOS_DIRECTORY_TYPE_ATTRIB;

typedef struct {
    BIOS_DIRECTORY_ENTRY_TYPE    EntryType;
    uint32_t                     *pDataSourceAddr;
    uint64_t                     *pDataDestAddr;
    uint32_t                     *pDataLength;
    BIOS_DIRECTORY_TYPE_ATTRIB   *pAttrib;
    uint8_t                      index;
} BIOS_DIR_SEARCH_PARMS;

typedef struct {
    uint32_t                     Size;                  // Size of (BIOS_DIR_SEARCH_PARMS_v2)
    void                         **pSmnBiosDirBaseAddr; // SMN address mapped by PSP on gBiosBaseAddr
    BIOS_DIRECTORY_ENTRY_TYPE    EntryType;
    uint32_t                     *pDataSourceAddr;
    uint64_t                     *pDataDestAddr;
    uint32_t                     *pDataLength;
    BIOS_DIRECTORY_TYPE_ATTRIB   *pAttrib;
    uint8_t                      index;
} BIOS_DIR_SEARCH_PARMS_V2;

#define NUM_HOLE                     1
#define NUM_MMIO                    16
#define NUM_DRAM                    20
#define MAX_MEM_DESC                (NUM_DRAM + NUM_MMIO + NUM_HOLE)
#define NUM_PRIV_MEM                 4

#define PSP_PRIVILEGE_REGION         0
#define SMU_PRIVILEGE_REGION         1
#define CC6_PRIVILEGE_REGION         2
#define DF_PRIVILEGE_REGION          3
#define TSEG_REGION                  4
#define MAX_MISC_DESC                5

typedef enum
{
    MEM_DESC_TYPE_DRAM      = 0x0,
    MEM_DESC_TYPE_MMIO      = 0x1,
    MEM_DESC_TYPE_MMIO_HOLE = 0x2,
    MEM_DESC_TYPE_MERGED    = 0x3,
} MEM_DESC_TYPE;

// For Memory Descriptor
typedef struct
{
    uint64_t Base;          // Base address
    uint64_t Limit;         // Limit, needs to be filled with F's
    uint32_t Type;          // Memory Descriptor Type (MEM_DESC_TYPE)
    uint32_t Attr;          // Hole enable, the rest are place holders.
} MEM_DESC;

// System Memory Map
typedef struct
{
    uint64_t Tom;           // Top of Memory below 4G, the MMIO Base, Hole
    uint64_t Tom2;          // Top of DRAM Memory
    uint64_t MmioBase64;    // Mmio Base beyond 4G
    uint32_t DescNum;       // Number of Memory Descriptor
    MEM_DESC MemRegion[MAX_MEM_DESC]; // Array of Memory Descriptors
} SYS_MEM_MAP;

typedef struct
{
    uint64_t Base;          // Base address
    uint64_t Length;        // Length
} ADDR_RANGE;

typedef struct
{
    uint64_t Base;          // Base
    uint64_t Limit;         // Limit
    uint32_t Config;        // Address Configuration
    uint32_t Offset;        // Offset
} PRIVILEGE_MEM_CFG;

//  System Memory Map
typedef struct
{
    SYS_MEM_MAP        SysMemMap;
    ADDR_RANGE         SmmRegion;
    PRIVILEGE_MEM_CFG  PrivilegeRegionCfg[NUM_PRIV_MEM];
} SYS_MEM_INFO;

// TMR configuration
/**
 * @enum TMR_OWNER_ID
 * @brief Indicates ownership of TMR request.
 *        Note that, one owner can have make multiple TMR setup request,
 *        as long as TMRs are available.
 */
typedef enum TMR_OWNER_ID_E {
    TMR_OWNER_SMM  = 0,
    TMR_OWNER_SEV  = 1,
    TMR_OWNER_DRTM_TMR_1 = 101,
    TMR_OWNER_DRTM_TMR_2 = 102,
    TMR_OWNER_SMM_TSEG_TMR = 103,
    TMR_OWNER_PSP_TMR    = 104,
    TMR_OWNER_DRTM_TMR_3 = 105,
    TMR_OWNER_DRTM_TMR_4 = 106,
    TMR_OWNER_DRTM_TMR_5 = 107,
    TMR_OWNER_MAX  = 3
} TMR_OWNER_ID;

/**
 * @struct SYS_TMR_CONFIG
 * @brief struct contains the parameters for TMR request
 */
typedef struct
{
    TMR_OWNER_ID tmr_owner_id;  // ID of the TMR request
    uint64_t   base_addr;       // Base address of the TMR memory
    uint32_t   size;            //  Size of the TMR memory
} SYS_TMR_CONFIG;

typedef enum {
    BIOS_PUBLIC_KEY    = 0x05,   // BIOS OEM public key, signed by AMD root private key
    BIOS_RTM_SIGNATURE = 0x07,   // Signed hash of RTM volume concatenated with BIOS DIRECTORY
    BIOS_APCB_INFO     = 0x60,   // Agesa PSP Customization Block (APCB)
    BIOS_APOB_INFO     = 0x61,   // Agesa PSP Output Block (APOB) target location
    BIOS_FIRMWARE      = 0x62,   // BIOS Firmware volumes, also referred as RTM volume with reset flag
    BIOS_APOB_DATA     = 0x63,   // Agesa PSP Output Block data and HMAC
    BIOS_APPB_IMEM     = 0x64,   // Agesa PMU FW IMEM
    BIOS_APPB_DMEM     = 0x65,   // Agesa PMU FW DMEM
    BIOS_UCODE_PATCH   = 0x66,
    BIOS_APCB_RO_INFO  = 0x68,   // Agesa RO PSP Customization Block (APCB)
    BIOS_ABL_VGA       = 0x6C,   // Agesa loading VGA information
    BIOS_VGA_E_IMG     = 0x69,

    BIOS_ABL_INSTANCE  = 0x6D, // Agesa loading VGA information
} BIOS_DIRECTORY_ENTRY_TYPE_E;

typedef enum {
    PSP_BOOT_MODE_S0          = 0x0,
    PSP_BOOT_MODE_S0i3_RESUME = 0x1,
    PSP_BOOT_MODE_S3_RESUME   = 0x2,
    PSP_BOOT_MODE_S4          = 0x3,
    PSP_BOOT_MODE_S5_COLD     = 0x4,
    PSP_BOOT_MODE_S5_WARM     = 0x5,
    PSP_BOOT_MODE_MAX         = 0x6,
} PSP_BOOT_MODE;

typedef enum {
    PSPBL_TEST_RESERVED = 0,
    PSPBL_TEST_DRAM_MEM_TEST,
    PSPBL_TEST_MPIO_CMD_TEST,
    PSPBL_TEST_MCA_MBAT_RESET,
    PSPBL_TEST_MCM_CPU_ONLY_BOOT,
    PSPBL_TEST_TSME_MEM_TEST,
    PSPBL_TEST_MCA_SET_OFFSET,
    PSPBL_TEST_MCA_GET_THD_COUNT,
    PSPBL_TEST_MCA_MBAT_WRITE,
    PSPBL_TEST_FW_VALIDATION,
    PSPBL_TEST_HMAC_SIGN_VALIDATE,
    PSPBL_TEST_P2P_COMM,
    PSPBL_TEST_ZLIB_DECOMP,
    PSPBL_TEST_CRYPTO_HAL,
    PSPBL_TEST_UTEST_SHA,
    PSPBL_TEST_READ_HARVEST_FUSES,
    PSPBL_TEST_GET_SYS_MEM_MAP,
    PSPBL_TEST_SME_MK,
    PSPBL_TEST_SVC_MICROSECOND_DELAY,
    PSPBL_TEST_MAX,
} PSPBL_TEST_CMD;

// TLB2_n settings for AWUSER and TLB3_n settings for ARUSER:
// USER[0] - ReqIO bit, 1'b1 for FCH MMIO address
// USER[1] - Compat bit, 1'b1 for FCH access, 0 for everything else
// USER[2] - ByPass_IOMMU bit, 1'b1 to always bypass IOMMU, 0 for IOMMU translation
typedef enum SYSHUB_TARGET_TYPE_E {
    // Target Type                    // Address                  // [2:0] =[ Bypass,Compat,ReqIO]
    AxUSER_PCIE_HT0            = 0x0, // PCIe HT (Bypass=0)       // [2:0] =[ 0,0,0]
    AxUSER_DRAM_VIA_IOMMU      = 0x1, // DRAM ACCESS via IOMMU    // [2:0] =[ 0,0,1]
    AxUSER_PCIE_HT1            = 0x2, // PCIe HT  (Bypass=1)      // [2:0] =[ 0,1,0]
    AxUSER_RSVD                = 0x3, // - NOT USED, INVALID      // [2:0] =[ 0,1,1]
    AxUSER_DRAM_BYPASS_IOMMU   = 0x4, // GENERAL DRAM             // [2:0] =[ 1,0,0]
    AxUSER_PCIE_MMIO           = 0x5, // PCIe MMIO                // [2:0] =[ 1,0,1]
    AxUSER_FCH_HT_IO           = 0x6, // FCH HT (port80)          // [2:0] =[ 1,1,0]
    AxUSER_FCH_MMIO            = AxUSER_FCH_HT_IO, // FCH MMIO
    AxUSER_MAX                 = 0xFF,
    SYSHUB_TARGET_TYPE_MAX_VAL = AxUSER_FCH_MMIO
} SYSHUB_TARGET_TYPE;

// System property ID
typedef enum PROP_ID_E {
    PROP_ID_SRTC                  = 0x1,
    PROP_ID_PPIN                  = 0x2,
    PROP_ID_TCB_VERSION           = 0x3,
    PROP_ID_SOC_VERSION           = 0x5,
    PROP_ID_SEV_INITPKG           = 0x6,
    PROP_ID_SET_ERR_STATUS        = 0x7,
    PROP_ID_GET_MCM_CPU_ONLY_MODE = 0x8,
    PROP_ID_SYS_MEM_MAP           = 0x9,
    PROP_ID_READ_SNP_GLOBALS      = 0xA,
    PROP_ID_WRITE_SNP_GLOBALS     = 0xB,
    PROP_ID_GET_MP1_OPN_FUSE      = 0xC,
    PROP_ID_SET_TMR               = 0xD,
    PROP_ID_SET_BOARD_TYPE        = 0xE,
    PROP_ID_GET_SDU_CTX           = 0x10,
    PROP_ID_SET_SDU_CTX           = 0x11,
    PROP_ID_PROGRAM_SRTC          = 0x12,
    PROP_ID_PRE_UNLOCK_NOTIFY     = 0x13,   // Prepare for unlock (SNP, PC6, ...)
    PROP_ID_GET_KDS_PUBLIC_KEY    = 0x14,
    PROP_ID_POLICY_VIOLATION_LOG  = 0x15,
    PROP_ID_DISABLE_SEV           = 0x20,
    PROP_ID_GET_SSCB              = 0x21,
    PROP_ID_SET_SNP_STATE         = 0x22,
//  PROP_ID_GET_SMU_VER           = 0x23,   // Currently unused
    PROP_ID_SET_SSCB_PHYS_ADDR    = 0x24,
    PROP_ID_GET_HASHSTICKS        = 0x26,
    PROP_ID_GET_SKIP_RSMU         = 0x27,
    PROP_ID_MAX_VAL
} PROP_ID;

// SOC Version number
//    CpuID_Stepping[3:0]
//    CpuID_Model[7:4]
//    CpuID_ExtModel[11:8]

typedef enum SOC_VER_E {
    INVAL_SOC_VER_VAL         = -0x1,
    A0_SOC_VER_VAL            = 0x0,
    B0_SOC_VER_VAL            = 0x10,
    B1_SOC_VER_VAL            = 0x11,
    C0_SOC_VER_VAL            = 0x20,
    C1_SOC_VER_VAL            = 0x21,
    SOC_VER_FORCE_32_BIT_ENUM = 0x7FFFFFFF /*!< [UNUSED] Added to force this enum to 32-bits */
} SOC_VER_E;

typedef enum CPUID_EXT_MODEL_E {
    INVAL_EXT_MODEL_VAL       = -0x1,
    CPUID_EXT_MODEL_CLASSIC   = 0x0,
} CPUID_EXT_MODEL_E;

typedef enum SDP_ENABLE_MASK_E {
    INVALID_CONFIG          = 0x0,
    NARROW_SDP0             = 0x1,
    NARROW_SDP1             = 0x2,
    WIDE_SDP                = 0x3,
    NARROW_2X               = 0x4
}SDP_ENABLE_MASK_E;

typedef struct SYSHUB_RW_PARMS_EX_E {
    uint32_t             SyshubAddressLo;
    uint32_t             SyshubAddressHi;
    uint32_t             *pValue;
    uint32_t             Size;
    SYSHUB_TARGET_TYPE   TargetType;
} SYSHUB_RW_PARMS_EX;

typedef struct AES_GENERIC_E {
    uint8_t         *Iv;
    size_t          IvLength;
    const uint8_t   *Key;
    size_t          KeyLength;
    uint32_t        KeyMemType;
    const uint8_t   *Src;
    size_t          SrcLength;
    uint32_t        SrcMemType;
    uint8_t         *Dest;
    size_t          DestLength;
    uint32_t        DestMemType;
    uint32_t        AesAlg;
    uint32_t        AesMode;
} AES_GENERIC;

typedef enum SEV_MODE_T {
    SEV_MODE_INVALID  = -1,
    SEV_MODE_DISABLED = 0,
    SEV_MODE_64TB     = 1, // 10-bit SEV mode
    SEV_MODE_MAX      = 2,
} SEV_MODE;

typedef enum {
    BOARD_TYPE_GENERIC          = 0,
} BOARD_TYPE;

/**
 * @struct MCA_MBAT_INFO
 * @brief This structure holds parameters required to write MBAT table onto S3 Save area MBAT region.
 */
typedef struct MCA_MBAT_INFO_T {
    /**< MCA_MBAT_INFO#logical_core, 0-7 bits are present here, the logical core whose MBAT is to be updated. */
    uint8_t  logical_core;
    /**< MCA_MBAT_INFO#phys_thread_id, 0-7 bits are present here, the physical thread ID of the logic core whose MBAT table is to be updated. */
    uint8_t  phys_thread_id;
    /**< MCA_MBAT_INFO#socket_id, socket_Id of the node whose MCA banks information are to be filled into
     * the logical core's MBAT table, non-0 only for remote none-CPU nodes (A+A configuration). */
    uint8_t   socket_id;
    /**< MCA_MBAT_INFO#die_id, die_id of the node whose MCA banks information are to be filled into
     * the logical core's MBAT table, non-0 only for remote none-CPU nodes (A+A configuration). */
    uint8_t   die_id;
    /**< MCA_MBAT_INFO#mbat_die_id, combined form of the above two fields (socket_id and die_id),
     * which will be filled into the MBAT table. */
    uint8_t   mbat_die_id;
    /**< MCA_MBAT_INFO#is_raz, read as zero, set to 1 if there is no more MCA banks to program.
     * The above 3 fields socket_id/die_id/mbat_die_id/thread_id are valid only if this field is 0. */
    bool      is_raz;
    /**<MCA_MBAT_INFO#remote_thread_id, (A+A only) thread ID of the node specified by (socket_id, die_id).
     * For GPU, this tells which column of the MCA banks of that node. Ignored for non A+A configurations. */
    uint8_t   remote_thread_id;
    /**<MCA_MBAT_INFO# logical core hi, 8-15 bits are present */
    uint8_t   logical_core_hi;
    /**<MCA_MBAT_INFO# physical thread id hi, 8-15 bits are present */
    uint8_t   phys_thread_id_hi;
    uint8_t   reserved[3];
} MCA_MBAT_INFO;

// This structure holds parameters required - S3 save area offsets for core banks ipid registers from ABL to ASP
typedef struct MCA_CORE_IPID_INFO_T {
    uint32_t    s3_mca_mc0_ls_ipid_offset;
    uint32_t    s3_mca_mc1_if_ipid_offset;
    uint32_t    s3_mca_mc2_l2_ipid_offset;
    uint32_t    s3_mca_mc3_de_ipid_offset;
    uint32_t    reserved0;
    uint32_t    s3_mca_mc5_ex_ipid_offset;
    uint32_t    s3_mca_mc6_fp_ipid_offset;
    uint32_t    reserved1;
} MCA_CORE_IPID_INFO;

// data for PROP_ID_GET_MCM_CPU_ONLY__MODE
typedef struct MCM_CPU_ONLY_MODE_T {
    // 0x00: Normal Boot Mode, 0x01: CPU/Master Only Boot Mode
    uint8_t   mcm_cpu_only_mode;
    uint8_t   reserved[3];
} MCM_CPU_ONLY_MODE;

#define MP0_FW_OVERRIDE_CPU_BOOT_MODE_VAL       (1 << 10)
#define MP0_FW_OVERRIDE_CPU_BOOT_MODE_MASK      (3 << 10)
#define MP0_FW_OVERRIDE_CPU_UNLOCK_STATUS_VAL   (1U << 2)
// error status format for PROP_ID_SET_ERR_STATUS
typedef struct MCM_ERROR_STATUS_T {
    uint32_t   error_code;
    uint32_t   slave_masks;
    uint8_t    is_fatal;
    uint8_t    reserved[7];
} MCM_ERROR_STATUS;

// This is data format passed in SVC for raw binary decompression
typedef struct ZLIB_OPS_PARAM_T {
    uint32_t dest_addr_lo;        // Destination memory in system address space.
    uint32_t dest_addr_hi;
    uint32_t dest_len;            // size in bytes, indicates size available in destination memory.
                                  // It is application's responsibility to make sure that there is
                                  // enough room to copy inflated image.
    uint8_t dest_addr_mode;       // Destination Address Mode (must be outside secure regions):
                                  // 0: AXI Address (only dest_add_lo used) (PSP will enforce the offset in UAPP address space)
                                  // 1: System address (General DRAM)(PSP will sanitize against PSP owned regions)
                                  // 2: System address (MMIO)(PSP will sanitize against PSP owned regions)

    uint8_t reserved0[3];

    uint32_t src_addr;           // Offset in SPIROM, pointing to compressed image.
                                 // Application will get the offset by using SVC_BIOSDirectorySearchV2() API
    uint32_t reserved1;          // Reserved for future, in case we want to support system addr
    uint32_t src_len;            // Size in bytes, indicates size of comressed image
    uint8_t src_addr_mode;       // Source Address Mode (must be outside secure regions):
                                 // 0: SPIROM Offset (PSP will enforce the offset to be in SPIROM address space)
                                 // 1: AXI Address (PSP will enforce the offset in UAPP address space)
    uint8_t zlib_op;             // ZLIB operation:
                                 // 0: Compression (CCP Architecture does not support it today)
                                 // 1: Decompression (Currently it only supports decompression)
    uint8_t reserved2[2];

} ZLIB_OPS_PARAM;

#define SMKE_DATA_KEY_LEN_IN_BYTES  32
#define SMKE_IV_KEY_LEN_IN_BYTES    32

typedef struct SMKE_LOAD_KEY_T
{
    uint8_t  key_number;                             // This field identifies the SME key number
                                                     // that is being loaded.
                                                     // This value must be > 0 and < the total number of
                                                     // SME-MK keys (63) supported.
    uint8_t  reserved0[63];                          // Reserved must be 0
    uint8_t  data_key[SMKE_DATA_KEY_LEN_IN_BYTES];   // Key used for encryption of data.
    uint8_t  reserved1[32];                          // Reserved must be 0
    uint8_t  iv_key[SMKE_DATA_KEY_LEN_IN_BYTES];     // IV Key can be used for algorithm IV or
                                                     // in the case of AES XTS mode, the XTS encryption key.
    uint8_t  reserved2[32];                          // Reserved must be 0
} SMKE_LOAD_KEY;

typedef struct SMKE_QUERY_T
{
    uint8_t  version;        // Version number, of the command,
                             // that is understood by the OS/HV.
                             // This value should be zero and
                             // may be needed in future updates to this command.
    uint8_t  reserved[7];    // Reserved must be 0
    uint64_t query_rsp_buf;  // Address for where the PSP should place the return data
} SMKE_QUERY;

typedef struct SMKE_QUERY_RSP_T
{
    uint8_t  version;        // Version number supported
    uint8_t  keys;           // Number of keys that can be loaded by a host.
    uint8_t  reserved[62];   // Reserved must be 0
} SMKE_QUERY_RSP;

// Master status bits [31:24] assigned as AGESA status bits. It is up to AGESA team
// to define individual bit values.
#define AGESA_MASTER_STATUS_BITS   0xFF000000

#define CLIENT_ID_AGESA            0

// MAP_SYSHUB related defines

// SysHub Inline AES defines
#define MA_AES_EN_VAL   0x1U
typedef enum MA_AES_KEY_SEL_E {
    MA_AES_KEY_0_SEL_VAL = 0,
    MA_AES_KEY_1_SEL_VAL = 1,
    MA_AES_KEY_2_SEL_VAL = 2,
    MA_AES_KEY_3_SEL_VAL = 3,
} MA_AES_KEY_SEL;

#define MA_AES_TWEAK_VAL           0
#define MP0_SYSHUB_AES_KEY0_0      mmMPASP_SYSHUB_AES_Key0_0

// SysHub TLB attribute shifting defines
#define MA_PSP_ARPROT_1_SHIFT      0
#define MA_PSP_AWPROT_1_SHIFT      1
#define MA_PSP_AES_KEY_SEL_SHIFT   13
#define MA_PSP_AES_EN_SHIFT        15
#define MA_PSP_CCP_SHIFT           23
#define MA_PSP_PUB_SHIFT           30
#define MA_PSP_PRIV_SHIFT          31

// SYSHUB_TLB_ATTRIBUTE configurations
#define INITIAL_TLB_ATTRIBUTE      ((0x1U << MA_PSP_PUB_SHIFT) | (0x1U << MA_PSP_PRIV_SHIFT))
#define INLINE_AES_EN              (MA_AES_EN_VAL << MA_PSP_AES_EN_SHIFT)
#define INLINE_AES_KEY0_SEL        (MA_AES_KEY_0_SEL_VAL << MA_PSP_AES_KEY_SEL_SHIFT)
#define INLINE_AES_KEY1_SEL        (MA_AES_KEY_1_SEL_VAL << MA_PSP_AES_KEY_SEL_SHIFT)
#define INLINE_AES_KEY2_SEL        (MA_AES_KEY_2_SEL_VAL << MA_PSP_AES_KEY_SEL_SHIFT)
#define INLINE_AES_KEY3_SEL        (MA_AES_KEY_3_SEL_VAL << MA_PSP_AES_KEY_SEL_SHIFT)
#define MA_PSP_CCP_SET             (0x1 << MA_PSP_CCP_SHIFT)
#define MA_PSP_ARPROT_1_SET        (0x1 << MA_PSP_ARPROT_1_SHIFT)
#define MA_PSP_AWPROT_1_SET        (0x1 << MA_PSP_AWPROT_1_SHIFT)
#define MA_PSP_PUB_SET             (0x1 << MA_PSP_PUB_SHIFT)
#define MA_PSP_PRIV_SET            (0x1 << MA_PSP_PRIV_SHIFT)

#define SEV_NEWFW_SUBOP_SHIFT 24     /* ENUM = (op >> SHIFT) & MASK */
#define SEV_NEWFW_SUBOP_MASK  0xFF   /* op = (ENUM & MASK) << SHIFT */

// Define config_id for the PSP bootloader GET/SET SVC  call
typedef enum USR_MODE_CONFIGID_E {
    USR_MODE_CONFIGID_RESERVED        = 0x0,
    USR_MODE_CONFIGID_SECURITY_STATE  = 0x29,
    SVC_CONFIG_ID_MP5_CORE_DISABLE    = 0x3A,
    SVC_CONFIG_ID_GET_MP5_SMT_ENABLE  = 0x40,
} USR_MODE_CONFIGID;

// Security state return from PSP Bootloader mapped to the Secure state return from BOOTROM defined in mp_reg.h
typedef enum MPASP_SECURITY_STATE_T
{
    MPASP_SECURITY_STATE_NOTRECOGNIZED   =   0x0,
    MPASP_SECURITY_STATE_BLANK           =   0x1,
    MPASP_SECURITY_STATE_FRA             =   0x2,
    MPASP_SECURITY_STATE_PROTO           =   0x3,
    MPASP_SECURITY_STATE_SECURE          =   0x4,
} MPASP_SECURITY_STATE;

/**
 * @brief Exit from the User Application
 * @details Exit to the main Boot Loader. This call does not return
 *          back to user application.
 *
 * @param Status - Either Ok or error code defined by User Application
 *
 * @return
 */
__svc(SVC_EXIT) void Svc_Exit(uint32_t Status);

/**
 * @brief Maps buffer for stack usage.
 * @details Maps the buffer passed by User space application to use it as stack.
 *
 * @param StartAddr   -   Start address of the stack buffer
 * @param EndAddr     -   End of the stack buffer
 * @param pStackVa    -   [out] Mapped stack Virtual Address
 *
 * @return BL_OK or error code
 */
__svc(SVC_MAP_USER_STACK) uint32_t Svc_MapUserStack(uint32_t StartAddr, uint32_t EndAddr, uint32_t *pStackVa);

/**
 * @brief Load and verify firmware binary
 * @details Loads and verifies firmware binary pointed by PSP/BIOS Directory entry.
 *
 * @param PspDirType  -   Type of PSP directory entry to load from
 * @param pDest       -   Memory address to load data to
 * @param pDestSize   -   [input] - Max pDest size, [output] - Actual loaded size
 *
 * @return value: BL_OK or error code
 */
__svc(SVC_LOAD_BINARY) uint32_t Svc_LoadBinary(BIOS_DIRECTORY_ENTRY_TYPE_E PspDirType, void *pDest, uint32_t *pDestSize);

/**
 *  @brief Map SMN address on given Die number
 *
 *  @details Map SMN TLB for access to SMN address on specific die in MCM configuration.
 *
 *  @param SmnAddress  -   address in SMN address space
 *  @param DieNum      -   die number on which the SMN address is located
 *
 *  @return on success - Mapped address in AXI space, On error - NULL
 */
__svc(SVC_MAP_SMN_ON_DIE_NUM) uintptr_t Svc_MapSmnOnDieNum(uint32_t SmnAddress, uint32_t DieNum);

/**
 *  @brief Map SMN address on the current die with given size.
 *
 *  @details Map SMN TLB for access to SMN address on the current die with given size.
 *
 *  @param smn_addr    - The local SMN address to be mapped.
 *
 *  @param size        - Total size to map.
 *
 *  @return on success - Mapped address in AXI space, On error - NULL
 */
__svc(SVC_MAP_SMN_WITH_SIZE) uintptr_t Svc_MapSmnWithSize(uint32_t smn_address, uint32_t size);

/**
 *  @brief Unmap previously mapped SMN address.
 *  @details Unmap SMN TLB for AXI address previously mapped using Svc_MapSmnOnCurrentDieWithSize().
 *
 *  @param  AxiAddress -   address in AXI address space previously mapped
 *                      using Svc_MapSmnOnCurrentDieWithSize()
 *
 *  @param size        - Total size to map.
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_UNMAP_SMN_WITH_SIZE) uint32_t Svc_UnmapSmnWithSize(uintptr_t AxiAddress, uint32_t size);

/**
 *  @brief Map SMN address on the current die.
 *
 *  @details Map SMN TLB for access to SMN address on the current die.
 *
 *  @param SmnAddress  -   address in SMN address space
 *
 *  @return on success - Mapped address in AXI space, On error - NULL
 */
__svc(SVC_MAP_SMN_ON_CURRENT_DIE) uintptr_t Svc_MapSmnOnCurrentDie(uint32_t SmnAddress);

/**
 *  @brief Unmap previously mapped SMN address.
 *  @details Unmap SMN TLB for AXI address previously mapped using Svc_MapSmnOnDieNum()
 *           or Svc_MapSmnOnCurrentDie().
 *
 *  @param  AxiAddress -   address in AXI address space previously mapped
 *                      using Svc_MapSmnOnDieNum() or Svc_MapSmnOnCurrentDie()
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_UNMAP_SMN) uint32_t Svc_UnmapSmn(uintptr_t AxiAddress);
/**
 *  @brief Set debug mode
 *  @details Enable or disable debug printing in simnow environment dynamically during runtime.
 *
 *  @param  fEnable -   1 to enable debug print output, 0 to disable
 *
 *  @return
 */
__svc(SVC_SET_DEBUG_STATE) void Svc_SetDebugState(uint32_t fEnable);

/**
 *  @brief Map SYSHUB address.
 *  @details Map SYSHUB TLB for access to SYSHUB address.
 *
 *  @param    SyshubAddressLo -   low order 32 bit of address in SYSHUB address space
 *  @param    SyshubAddressHi -   high order 32 bit of address in SYSHUB address space
 *
 *  @return value: On success - Mapped address in AXI space, On error - NULL
 */
__svc(SVC_MAP_SYSHUB) void *Svc_MapSysHub(uint32_t SyshubAddressLo, uint32_t SyshubAddressHi);

/**
 *  @brief Unmap previously mapped SYSHUB address.
 *  @details Unmap SYSHUB TLB for AXI address previously mapped using Svc_MapSyshub().
 *
 *  @param    pAxiAddress -   address in AXI address space previously mapped
 *                      using Svc_MapSyshub()
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_UNMAP_SYSHUB) uint32_t Svc_UnmapSysHub(void *pAxiAddress);

/**
 *  @brief Read 32-bit value from SYSHUB address.
 *  @details
 *
 *  @param    SyshubAddressLo -   low order 32 bit of address in SYSHUB address space
 *  @param    SyshubAddressHi -   high order 32 bit of address in SYSHUB address space
 *  @param    pValue          -   location for the value to be written
 *  @param    Size            -   size of the value in bytes; valid values: 1, 2 and 4
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_READ_SYSHUB) uint32_t Svc_ReadSysHub(uint32_t SyshubAddressLo, uint32_t SyshubAddressHi, uint32_t *pValue, uint32_t Size);

/**
 *  @brief Write 32-bit value to SYSHUB address.
 *  @details
 *
 *  @param    SyshubAddressLo -   low order 32 bit of address in SYSHUB address space
 *  @param    SyshubAddressHi -   high order 32 bit of address in SYSHUB address space
 *  @param    Value           -   value to be written
 *  @param    Size            -   size of the value in bytes; valid values: 1, 2 and 4
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_WRITE_SYSHUB) uint32_t Svc_WriteSysHub(uint32_t SyshubAddressLo, uint32_t SyshubAddressHi, uint32_t Value, uint32_t Size);

/**
 *  @brief Calculate SHA256
 *  @details
 *
 *  @param    pData           -   Address of the data to be hashed
 *  @param    DataLen         -   Length of data to be hashed
 *  @param    pHash           -   Hashed ouput
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_SHA256) uint32_t Svc_SHA256(char *pData, uint32_t DataLen, char *pHash);

/**
 *  @brief Calculate ModEx
 *  @details
 *
 *  @param pModExParams -   ModExp parameters
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_MODEXP) uint32_t Svc_MODEXP(MOD_EXP_PARAMS *pModExParams);

/**
 *  @brief RSA PSS Verification of signature and data
 *  @details
 *
 *  @param pRSAPSSParams - Pointer to RSA PSS parameters
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_RSAPSS_VERIFY) uint32_t Svc_RSAPSSVerify(RSAPSS_VERIFY_PARAMS *pRSAPSSParams);

/**
 *  @brief AES ECB Encrypt
 *  @details
 *
 *  @param pAesEcbEncryptParam -  AES ECB Encrypt parameters
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_AES_ECB_ENCRYPT) uint32_t Svc_AesEcbEncrypt(AES_ECB_ENCRYPT_PARAMS *pAesEcbEncryptParam);

/**
 *  @brief  Compute SHA256 hash of OTP Key slot 0
 *  @details
 *
 *  @param pHash - Hash output
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_SHA256_OTP) uint32_t Svc_Sha256OTP(char *pHash);

/**
 *  @brief Get MCM configuration info (number of dies/sockets etc.).
 *  @details
 *
 *  @param    pMcmInfo    -   output buffer
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_GET_MCM_INFO) uint32_t Svc_GetMcmInfo(void *pMcmInfo);

/**
 *  @brief  Broadcast data from global master to all slaves. Broadcast happens through
 *  8 32-bit registers, so input data is array of 32-bit values.
 *  @details
 *
 *  This can only be called on master die.
 *
 *  @param    ClientId        -   client ID
 *  @param    MasterStatusBit -   master status to be set when broadcast data is ready
 *  @param    pData           -   input data (array of 32-bit values)
 *  @param    Num             -   number of 32-bit elements in the array; must not be 0
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_MASTER_BROACAST) uint32_t Svc_McmBroadcastDataToSlaves(uint32_t ClientId, uint32_t MasterStatusBit, uint32_t *pData, uint32_t Num);

/**
 *  @brief  Slave reads broadcast configuration data from master. Broadcast happens
 *  through 8 32-bit registers, so output data is array of 32-bit values.
 *  @details
 *
 *  This can only be called on slave dies.
 *
 *  @param    ClientId        -   client ID
 *  @param    MasterStatusBit -   master status for slaves to wait before reading the data
 *  @param    pOut            -   output data (array of 32-bit values); can be NULL if this
 *                                particular slave does not want to read any data (it still
 *                                has to acknowledge the read to master)
 *  @param    Num             -   number of 32-bit elements in the array
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_SLAVE_GET_BROACAST_DATA) uint32_t Svc_McmGetBroadcastDataFromMaster(uint32_t ClientId, uint32_t MasterStatusBit, uint32_t *pOut, uint32_t Num);

/**
 *  @brief Reads BIOS Directory into global buffer, and searches the directory for an entry
 *
 *  @param pParms  - Pointer to BIOS_DIR_SEARCH_PARMS, where,
 *                     EntryType       - Entry to be searched
 *                     pDataSourceAddr - return the offset of BIOS entry within SPI-ROM image
 *                     pDataDestAddr   - return the destination address that the entry indicates
 *                     pDataLength     - return the length of the entry
 *                     pAttrib         - return the specific attributes of the entry type
 *                     Instance        - the InstanceType of the specific entry type to search for
 *
 *  @return Values    : BL_OK or error code
 */
__svc(SVC_SEARCH_BIOS_DIR) uint32_t SVC_BIOSDirectorySearch(BIOS_DIR_SEARCH_PARMS *pParms);

/**
 *  @brief Reads BIOS Directory into global buffer, and searches the directory for an entry
 *         Version 2 and will be used to replace SVC_SEARCH_BIOS_DIR
 *  @details
 *
 *  @param pParms - Pointer to BIOS_DIR_SEARCH_PARMS_V2, where,
 *                     Size            - Size of (BIOS_DIR_SEARCH_PARMS_v2)
 *                     pSmnBiosDirBaseAddr - Base SMN address mapped by PSP of BIOS DIR Table
 *                     EntryType       - Entry to be searched
 *                     pDataSourceAddr - return the offset of BIOS entry within SPI-ROM image
 *                     pDataDestAddr   - return the destination address that the entry indicates
 *                     pDataLength     - return the length of the entry
 *                     pAttrib         - return the specific attributes of the entry type
 *                     Instance        - the InstanceType of the specific entry type to search for
 *
 * @return Values    : BL_OK or error code
 */
__svc(SVC_SEARCH_BIOS_DIR_V2) uint32_t SVC_BIOSDirectorySearchV2(BIOS_DIR_SEARCH_PARMS_V2 *pParms);

/**
 *  @brief Get data from one or more slave dies
 *  @details
 *
 *  @param    ClientId         - Client Id
 *  @param    pData            - Input/output pointer to place returned data
 *  @param    pDataSize        - Input/output pointer to place return data block size (max 32Bytes)
 *  @param    pSlaveId         - Input/output pointer to place returning ID of slave
 *
 *  @return value: BL_OK, BL_ERR_MORE_DATA, or a BL error
 */
__svc(SVC_GET_DATA_FROM_SLAVES) uint32_t Svc_GetDataFromSlaves(uint32_t ClientId, uint32_t *pData, uint32_t *pDataSize, uint32_t *pSlaveId);

/**
 *  @brief Send data from slave to the local master
 *  @details
 *
 *  @param    ClientId        - Client Id
 *  @param    pData           - Input pointer containing data to send (max 32Bytes)
 *  @param    DataSize        - Input integer containing number of 32bit DWORDs to send
 *  @param    Eod             - Input integer containing EoD signal when done sending blocks (0 or 1)
 *
 *  @return value: BL_OK, or another BL error
 */
__svc(SVC_SEND_DATA_TO_MASTER) uint32_t Svc_SendDataToMaster(uint32_t ClientId, uint32_t *pData, uint32_t DataSize, uint32_t Eod);

/**
 *  @brief Waits in a blocking call for multiples of 10ns (100MHz timer) before returning
 *  @details
 *
 *  @param    Multiple        - The number of multiples of 10ns to wait
 *
 *  @return value: BL_OK, or BL_ERR_TIMER_PARAM_OVERFLOW
 */
__svc(SVC_WAIT_10NS_MULTIPLE) uint32_t Svc_Wait10nsMultiple(uint32_t Multiple);

/**
 *  @brief Returns the current boot mode from the type PSP_BOOT_MODE found in
 *         bl_public.h.
 *  @details
 *
 *  @param pBootMode - Output parameter passed in R0
 *                     The boot mode in pBootMode.
 *                     See @return Values.
 *
 * @return Values    : BL_OK, or another BL error
 */
__svc(SVC_GET_BOOT_MODE) uint32_t Svc_GetBootMode(uint32_t *pBootMode);

/**
 *  @brief  Returns the parameter for debug unlock information
 *          bl_public.h.
 *  @details
 *
 *  @param pData  - Address point to DebugUnlockInfo Structure.
 *  @param pKdsPubKey - a pointer to copy the KDS public key to
 *  @param KeyLen - the length of the key in bytes
 *
 *  @return Values    :   BL_OK, or another BL error
 */
//__svc(SVC_GET_DEBUG_UNLOCK_INFO) uint32_t Svc_GetDebugUnlockInfo(void *pData, void *pKdsPubKey, uint32_t KeyLen);

/**
 * @brief Send the request to slaves to perform the unlock with the provided information,
 *        while saving it back to BL gUnlockInfo structure
 * @details
 *
 *  @param pData  - Address point to DebugUnlockInfo Structure.
 *
 * @return Values    :   BL_OK
 */
__svc(SVC_SLAVE_UNLOCK_REQUEST) uint32_t Svc_SlaveUnlockRequest(void *pData);

/**
 * @brief Communicate the debug unlock information back to BL
 *        bl_public.h.
 * @details
 *
 * @param pData  - Address point to DebugUnlockInfo Structure.
 *
 * @return Values    :   BL_OK
 */
//__svc(SVC_SET_DEBUG_UNLOCK_INFO) uint32_t Svc_SetDebugUnlockInfo(void *pData);

/**
 * @brief Each die should call this SVC call to PSP boot loader to sign
 *        S3 data for each die. The master should call Svc_SaveAPOBData()
 *        once each PSP die completed the signing of the HMAC data
 * @details
 *
 * @param pHmac     [out] - Location in SRAM to copy HMAC to
 * @param DataSize  [in]  - Size of data to HMAC
 * @param pS3Data   [in]  - Data to HMAC
 *
 * @return values    : BL_OK or error code
 */
__svc(SVC_OTP_HMAC256_SIGN) uint32_t Svc_OTPHmac256Sign(uint8_t *pHmac, uint32_t DataSize, uint8_t *pS3Data);

/**
 * @brief  SVC call to PSP boot loader to HMAC 256 sign or validate data
 * @details   Calculate HMAC 256 bits using derived APOB HMAC key.
 *            This API can calculate new HMAC or validate older HMAC
 *            based on hmacOp flag parameter.
 *            This will use a special gApobHmacKey rather than the
 *            internal gHmacKey
 *         ** In multi-Socket configuration, for VALIDATE operation, this API must be
 *            called by both Master and Slave, as PSP FW will share HMAC result to
 *            Slave always.
 *
 * @param pData    [in]     - Data to HMAC Sign/Validate
 * @param DataSize [in]     - Size of data to HMAC
 * @param pHmac    [in/out] - Location in SRAM to copy HMAC to
 * @param HmacOp   [in]     - Flag to indicate Sign or Validate operation
 *
 * @return Values    : BL_OK or error code
 */
__svc(SVC_HMAC256_SIGN_VALIDATE) uint32_t Svc_Hmac256(uint8_t *pData, uint32_t DataSize, uint8_t *pHmac, uint8_t HmacOp);

/**
 * @brief Validates HMAC and loads S3 data. Each die should call
 *        this during S3 resume to get the APOB data
 * @details
 *
 * @param DataApobOffset [in]  - S3 DataInfo offset from APOB entry 0x63
 * @param pDestAddr      [out] - SRAM location to be copied
 * @param DataSize       [in]  - S3 DataSize in bytes to read
 * @param HmacApobOffset [in]  - SpiOffset from APOB entry where HMAC is stored
 *                               Will read 32 bytes from offset value provided
 *
 * @return Values    : BL_OK or error code
 */
__svc(SVC_SPILOAD_VALIDATE_HMAC256_APOB) uint32_t Svc_LoadValidateAPOBHmac256(uint32_t DataApobOffset,
                                                                              uint8_t  *pDestAddr,
                                                                              uint32_t DataSize,
                                                                              uint32_t HmacApobOffset);

/**
 * @brief Programs UMC keys
 * @details Generating them on S5, and restoring them from DRAM for S3.
 *          UMC keys must be shared between dies on S5 using DRAM as a shared mailbox,
 *          and restored from DRAM on S3.
 *          Therefore DRAM MUST be trained and PSP should be able to access PSP Secure Memory
 *          before AGESA calls Svc_ProgramUmcKeys().
 *
 * @param Flags bitfields:
 *                  UMC_DATA_ENCR_EN          BIT0
 *                  UMC_FORCE_ENCR_EN         BIT1
 *                  UMC_DATA_SCRAMBLE_EN      BIT2
 *                  UMC_KEY_0_DEFAULT_VALUE   BIT3
 *                  UMC_AES256_EN             BIT4
 *                  UMC_AESXTS_EN             BIT5
 *                  CNLI_ENCR_EN              BIT6
 *                  UMC_SMEMK_EN              BIT7

 * @param DisAddrTweak - Bitmask to disable address-tweak.
 *
 * @return Values    :   BL_OK or error code
 */
__svc(SVC_PROGRAM_UMC_KEYS) uint32_t Svc_ProgramUmcKeys(uint32_t Flags, uint16_t DisAddrTweak);

/**
 *  @brief Sync on Data between multiple PSP nodes.
 *  @details For MCM master - gathering the 32 bit information from each slave and storing in the array pointed with `data`
 *           For MCM slaves - sending the 32-bit data pointed by `data` to the master
 *
 *  @param data - Data to be on synced.
 *
 *  @return value: BL_OK, or a BL_ERROR code
 */
__svc(SVC_MCM_SYNC_ON_DATA) uint32_t Svc_McmSyncOnData(uint32_t *data);

/**
 *  @brief Map 64-bit SYSHUB target address for access via 32-bit AXI address  (Extended functionality).
 *  @details
 *
 *  @param    SyshubAddressLo -   low order 32 bit of address in SYSHUB address space
 *  @param    SyshubAddressHi -   high order 32 bit of address in SYSHUB address space
 *  @param    TargetType - type of SYSHUB target
 *
 *  @return value: On success - mapped address in AXI space. On error - NULL
 */
__svc(SVC_MAP_SYSHUB_EX) void *Svc_MapSysHubEx(uint32_t SyshubAddressLo, uint32_t SyshubAddressHi, SYSHUB_TARGET_TYPE TargetType);

/**
 *  @brief  Read 32-bit value from SYSHUB address (Extended functionality).
 *  @details
 *
 *  @param pParms  - Pointer to SYSHUB_RW_PARMS_EX, where,
 *      SyshubAddressLo - low order 32 bit of address in SYSHUB address space
 *      SyshubAddressHi - high order 32 bit of address in SYSHUB address space
 *      pValue          - destination pointer
 *      Size            - size of read value in bytes; valid values: 1, 2 and 4
 *      TargetType      - type of SYSHUB target
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_READ_SYSHUB_EX) uint32_t Svc_ReadSysHubEx(SYSHUB_RW_PARMS_EX *pParms);

/**
 *  @brief  Write 32-bit value to SYSHUB address (Extended functionality).
 *  @details
 *
 *  @param pParms  - Pointer to SYSHUB_RW_PARMS_EX, where,
 *      SyshubAddressLo - low order 32 bit of address in SYSHUB address space
 *      SyshubAddressHi - high order 32 bit of address in SYSHUB address space
 *      pValue          - source pointer
 *      Size            - size of read value in bytes; valid values: 1, 2 and 4
 *      TargetType      - type of SYSHUB target
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_WRITE_SYSHUB_EX) uint32_t Svc_WriteSysHubEx(SYSHUB_RW_PARMS_EX *pParms);

/**
 *  @brief Send an SMU/SMC message from PSP to SMU, and block until a response is received.
 *  @details
 *
 *  @param    MsgId       - PSP2SMU message id to send (no error checking is done on validity)
 *  @param    MsgArg      - DWORD containing message specific payload/arguments
 *  @param    pMsgResp    - pointer to store response read/returned from SMU
 *  @param    MsgRespSize - How many response bytes to return in pMsgResp
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_SEND_PSP_SMU_MSG) uint32_t Svc_SendPspSmuMsg(uint32_t MsgId, uint32_t MsgArg,
                                                       uint32_t *pMsgResp, uint32_t MsgRespSize);

/**
 *  @brief Set PSP/SMU firmware reserved memory address and size
 *  @details
 *
 *  @param ModuleId - Module ID for which memory is being reserved
 *  @param PhysAddrLo - Lower 32bit of 64 bit physical address
 *  @param PhysAddrHi - Upper 32bit of 64 bit physical address
 *  @param Size - Size of allocated memory
 *
 *  @return BL_OK or error code
 */
__svc(SVC_SET_RESERVED_DRAM) uint32_t Svc_SetPspSmuReservedAddrs(RESERVED_DRAM_MODULE_ID    ModuleId,
                                                                 uint32_t                   PhysAddrLo,
                                                                 uint32_t                   PhysAddrHi,
                                                                 uint32_t                   Size);

/**
 * @brief Usused
 *
 * @return BL_OK or error code
 */
__svc(SVC_GMI_NON_FUNCTIONAL) uint32_t Svc_GmiNonFunctional(void);

/**
 *  @brief Load a binary from the BIOS directory table by instance type.
 *         The binary should be signed, and can be compressed.
 *  @details
 *
 *  @param    BiosDirType     - From entry header in BIOS directory table.
 *  @param    pDest           - Pointer to where the binary should be loaded to.
 *  @param    pDestSizeBytes  - Input/Output parameter: on input, max size. On output, size of binary loaded.
 *  @param    InstanceType    - From entry header in BIOS directory table. An entry matching both BiosDirType and
 *                        InstanceType must be found in the BIOS directory table to load the bin.
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_LOAD_FW_IMAGE_BY_INSTANCE) uint32_t Svc_LoadBinaryByInstance(BIOS_DIRECTORY_ENTRY_TYPE_E BiosDirType,
                                                                       void                        *pDest,
                                                                       uint32_t                    *pDestSizeBytes,
                                                                       uint32_t                    InstanceType);

/**
 *  @brief  Load binary by attribute
 *  @details  Load a binary from the BIOS directory table by its attributes word.
 *            The binary should be signed unless it is of the excepted types, and can be
 *            compressed.
 *
 *  @param    AttribWord      - is the 32-bit long bit-coded attributes word
 *  @param    AttribMask      - is the mask with 1s in the places corresponding to the attributes to be searched
 *  @param    pDest           - Pointer to where the binary should be loaded to.
 *  @param    pDestSizeBytes  - Input/Output parameter: on input, max size. On output, size of binary loaded.
 *
 *  @return value - BL_OK or error code
 */
__svc(SVC_LOAD_BINARY_BY_ATTRIB) uint32_t Svc_LoadBinaryByAttrib(uint32_t AttribWord, uint32_t AttribMask, void *pDest, uint32_t *pDestSizeBytes);

/**
 *  @brief Program GMI and xGMI keys
 *  @details  Programs GMI and xGMI keys, according to parameters, and enables encryption.
 *            Three out of six CAKEs on each die are programmed for GMI, and one CAKE on
 *            each die is programmed for xGMI.
 *
 *  @param    IsGmiEncrypted - True -> Ciphertext GMI transactions, False -> Plaintext GMI transactions
 *  @param    IsXGmiEncrypted - True -> Ciphertext xGMI transactions, False -> Plaintext xGMI transactions
 *
 *  @return BL_OK or error code
 */
__svc(SVC_GMI_NONCE_KEY_PROGRAM) uint32_t Svc_GmiXGmiLinkKeyProgram(bool IsGmiEncrypted, bool IsXGmiEncrypted);

/**
 * @brief Function to do generic AES operation
 * @details
 *
 * @param pParams

 * @return BL_OK or error code
 */
__svc(SVC_AES_GENERIC) uint32_t Svc_AesGeneric(void *pParams);

/**
 * @brief Function to do cache operation
 * @details
 *
 * @param Operation Cache Operation to perform
 * @param CacheType Type of Cache
 * @param VirtAddr AXI Virtual address on which Cache operation to be performed
 * @param Size Size of memory on which cache operation to be performed.
 *
 * @return BL_OK or error code
 */
__svc(SVC_CACHE_OPERATION) uint32_t Svc_CacheOperation(uint32_t Operation, uint32_t CacheType, uint32_t VirtAddr, uint32_t Size);

/**
 * @brief Function to generate random number
 * @details
 *
 * @param pOut        -  Destination pointer to copy random data
 * @param Size        -  Size of Random number desired in Bytes
 *
 * @return BL_OK or error code
 */
__svc(SVC_TRNG) uint32_t Svc_Trng(uint8_t *pOut, uint32_t Size);

/**
 * @brief Function to retrieve the chip-unique ECC key from the LSB
 * @details
 *
 * @param buffer
 * @param size
 *
 * @return BL_OK or error code
 */
__svc(SVC_GET_CUK) uint32_t Svc_GetCUK(uint8_t *buffer, size_t *size);

/**
 * @brief Retrieve the base address and length of the SMM region
 * @details
 *
 * @param base
 * @param length
 *
 * @return BL_OK or error code
 */
__svc(SVC_GET_SMM_RANGE) void Svc_GetSmmRange(uint64_t *base, uint64_t *length);

/**
 * @brief This should be called by ABL to set the MIN_SEV_ASID value
 * @details
 *
 * @param MinSevAsid
 *
 * @return
 */
__svc(SVC_SET_MIN_SEV_ASID) void Svc_SetMinSevAsid(uint32_t MinSevAsid);

/**
 * @brief Enable/Disable debug mode.
 * @details
 * @param DebugMode =  0 - Release mode (CF9 Reset)
 *                     1 - Full Debug mode.
 *
 *  @return MinSevAsid
 */
__svc(SVC_SET_PSP_DEBUG_MODE) uint32_t Svc_SetPSPDebugMode(uint32_t DebugMode);

/**
 * @brief This should be called in order to set SYSHUB watchdog timer timeout configuration.
 * @details *
 *
 * @param nbioInstId - NBIO instance to which this interval should be applied.
 *                     Pass 0xFFFF_FFFF to set all available instances of NBIO with the specified interval configuration.
 * @param msec - Interval time for timeout in msec.
 *               Minimum timer value = 1ms. Max timer value =85850 msec.
 *               set 0 msec = To disable the timer. This will reset the SYSHUB MP error detection register
 *
 *  @return value: BL_OK or error code
 */
__svc(SVC_SET_SYSHUB_WDTTIMER_INTERVAL) uint32_t Svc_SetSysHubWdtTimerInterval(uint32_t nbioInstId, uint32_t msec);

/**
 * @brief Reset MBAT entry
 * @details  Resets the MBAT entry, by resetting it to NULL entry or
 *           by setting it to default value as per PPR document
 *
 * @param SmnAddress     - MCA bank address which needs to be reset
 * @param phys_thread_id - Master core id that this MCA bank belongs to.
 *
 * @return Values    -  BL_OK
 *                      Other BL_ERRORs lofted up from called functions
 */
__svc(SVC_MCA_RESET_MBAT_ENTRY) uint32_t Svc_McaResetMbatEntry(uint32_t SmnAddress, uint32_t phys_thread_id);

/**
 *  @brief Load FW Sub Type from SPIROM into memory
 *  @details
 *
 *  @param PspDirType  -   type of PSP directory entry to load from
 *  @param FWSubType   -   Sub Type to be loaded in memory
 *  @param pDest       -   memory address to load data to
 *  @param pDestSize   -   on input - max pDest size, on output - actual loaded size
 *
 * @return value: BL_OK or error code
 */
__svc(SVC_LOAD_BINARY_FROM_SUBTYPE) uint32_t Svc_LoadBinaryFromSubtype(uint32_t PspDirType,
                                                                       uint32_t                    FWSubType,
                                                                       void                        *pDest,
                                                                       uint32_t                    *pDestSize);

/**
 * @brief Generic SHA call for SHA, SHA_OTP, SHA_HMAC
 * @details
 *
 * @param pSHAOp  - Pointer to SHA_OPERATION
 * @param SHAMode - Mode of SHA operation
 *
 * @return BL_OK or error code
 */
__svc(SVC_SHA) uint32_t Svc_SHA(SHA_OPERATION *pSHAOp, SHA_OPERATION_MODE SHAMode);

/**
 * @brief Returns the PSP BL version
 * @details
 *
 * @param  pPspVersion - Version of the PSP BL
 *
 * @return Values    :   BL_OK - The command is completed successfully
 */
__svc(SVC_GET_PSP_VERSION) uint32_t Svc_GetPspVersion(uint32_t *pPspVersion);

/**
 * @brief  Get and/or Set a System Property
 * @details
 *
 * @param  prop_id     - Id of the the system property
 * @param  buffer_size - Size of the buffer that stores property information
 * @param  pBuffer     - Pointer to buffer to GET/SET property information
 *
 *
 * @return Values    :  BL_OK                        - The command is completed successfully
 *                      BL_ERR_INVALID_SERVICE_ID    - The input property id is not supported
 *                      BL_ERR_OUT_OF_RESOURCES      - The input buffer size is not sufficient
 */
__svc(SVC_GETSET_SYS_PROP) uint32_t Svc_GetSetSystemProperty(PROP_ID prop_id, uint8_t *pBuffer, uint32_t buffer_size);

/**
 * @brief Reads the harvest fuse ram bit sequence
 * @details
 *
 * @param StartBit - the bit number in the fuse RAM. Should be multiple of 32
 * @param NumBits  - total number of bits to read. will be rounded up to 32-bit boundary.
 *
 * @param pOutBuff - Pointer to buffer that stores fuse bits information
 *
 *
 * @return Values    :  BL_OK                        - The command is completed successfully
 *                      BL_ERR_INVALID_PARAMETER     - The input parameters StartBit/Numbits is/are incorrect
 */
__svc(SVC_READ_HARVEST_FUSE) uint32_t Svc_ReadHarvestFuseBits(uint32_t *pOutBuff, uint32_t StartBit, uint32_t NumBits);

/**
 * @brief  Map SYSHUB TLB for access to SYSHUB address.
 * @details
 *
 * @param SyshubAddressLo -     low order 32 bit of address in SYSHUB address space
 * @param SyshubAddressHi -     high order 32 bit of address in SYSHUB address space
 * @param TargetType      -     type of SYSHUB target
 * @param SyshubTlbAttributes - TLB Attributes configured in MP::MP0SHUBIF::MP0_SYSHUB_TLB_ATTRIBUTE_x register
 *
 * @return Values  - on success  -   mapped address in AXI space
 *                   on error    -   NULL
 */
__svc(SVC_MAP_SYSHUB_GENERIC) void *Svc_MapSysHubGeneric(uint32_t           SyshubAddressLo,
                                                         uint32_t           SyshubAddressHi,
                                                         SYSHUB_TARGET_TYPE TargetType,
                                                         uint32_t           SyshubTlbAttributes);

/**
 * @brief Exchange data with Slaves
 * @details With this API user space application can exchange any amount of data (<=4096 Bytes)
 *          with any slave or all slaves (in broadcast mode).
 *
 * @param pData  - Pointer address of P2P_DATA_BUF data type
 *                 P2P_DATA_BUF has the below mentioned elements
 *  cmd_id               - Command to send to slave
 *  slave_id             - Send CMD to any slave or all slaves (in broadcast mode).
 *                         for broadcast mode: send (0xFF) as slave_id
 *  continuous_cmd_flag  - Slave will wait for next cmd if it is set
 *  data                 - Data to send to slave
 *  size                 - Size of the data
 *  pslave_data          - Slave response
 *
 *
 * @return Values - BL_OK - The command is completed successfully
 *                  specific error BL_RETCODE for error condition
 *
 */
__svc(SVC_P2P_EXCHANGE_DATA_WITH_SLAVES) uint32_t Svc_P2PExchangeDataWithSlaves(P2P_DATA_BUF *pData);

/**
 * @brief Sync master and slave
 * @details With this API user app can sync master and slave
 *          using major FW module number and minor sync point num
 *
 * @param major   -    major FW module number defined at P2P_SYNC_FW_MODULE
 * @param minor   -    minor sync point num specific to calling FW module
 *
 * @return Values - BL_OK - The command is completed successfully
 *                  specific error BL_RETCODE for error condition
 */
__svc(SVC_P2P_SYNC_ON) uint32_t Svc_P2PSyncOn(P2P_SYNC_FW_MODULE_MAJOR_NUM major, uint32_t minor);

/**
 * @brief Wait for master cmd
 * @details With this API user app on slave soc
 *          can wait from slave to get cmd from master
 *
 * @param node_id     -     slave_id/node_id to communicate
 * @param pcmd        -     pointer of p2p cmd buffer which slave fill with cmd data from master
 * @param presp       -     pointer of slave response data
 *
 * @return Values - BL_OK - The command is completed successfully
 *                  specific error BL_RETCODE for error condition
 */
__svc(SVC_P2P_WAIT_FOR_CMD) uint32_t Svc_P2PWaitForCmd(uint32_t node_id, p2p_cmd_t *pcmd, p2p_buf_t *presp);

/**
 * @brief Send resp to master
 * @details With this API user app on slave soc can get
 *          send resp to master for last unfinished cmd
 *
 * @param node_id     -     slave_id/node_id to communicate
 * @param presp       -     pointer of slave response data
 *
 * @return Values - BL_OK - The command is completed successfully
 *                  specific error BL_RETCODE for error condition
 */
__svc(SVC_P2P_SEND_RESPONSE) uint32_t Svc_P2PSendResponse(uint32_t node_id, p2p_resp_t *presp);

/**
 * @brief Send cmd to master
 * @details With this API user app can send data to slave from master
 *
 * @param node_id     -     slave_id/node_id to communicate
 * @param pcmd        -     pointer of p2p cmd buffer which slave fill with cmd data from master
 * @param presp       -     pointer of slave response data
 * @param cc_flag     -     continuous command flag
 *
 * @return Values - BL_OK - The command is completed successfully
 *                  specific error BL_RETCODE for error condition
 */
__svc(SVC_P2P_SEND_CMD) uint32_t Svc_P2PSendCmd(uint32_t node_id,
        p2p_cmd_t* pcmd, p2p_resp_t *presp, uint32_t cc_flag);

/**
 * @brief  Wait for slave response
 * @details With this API user app can get resp from slave for last unfinished cmd comm
 *
 * @param node_id     -     slave_id/node_id to communicate
 * @param presp       -     pointer of slave response data
 *
 * @return Values - BL_OK - The command is completed successfully
 *                  specific error BL_RETCODE for error condition
 */
__svc(SVC_P2P_WAIT_FOR_RESP) uint32_t Svc_P2PWaitForResp(uint32_t node_id, p2p_resp_t *presp);

/**
 *  @brief Returns Mca Thread Count
 *  @details
 *
 *  @param socket_id      - To Decide whether it is local or remote Socket
 *  @param die_id         - Die id on the local or remote Socket
 *  @param p_thread_count - Thread Count belongs to Socket & Die ID.
 *
 *
 * @return Values         - BL_OK - The command is completed successfully
 *                          specific error BL_RETCODE for error condition
 *
 */
__svc(SVC_MCA_GET_MASTER_THREAD_COUNT) uint32_t Svc_McaGetMasterThreadCount(uint32_t socket_id, uint32_t die_id, uint32_t *p_thread_count);

/**
 * @brief   PSP BL Receives Offsets required for Mbat Table Programming from ABL.
 * @details
 *
 * @param mbat_offset         - To calculate the MbatAddress for Correponding Mbat Id
 * @param smca3_offset        - Offset of SMC a3 where corresponding mode will be updated
 * @param s3_save_area_offset - Offset to S3 Save Area where Mbat data needs to be updated
 *
 * @return Values    :   BL_OK - The command is completed successfully
 *                      specific error BL_RETCODE for error condition
 *
 */
__svc(SVC_MCA_SET_MBAT_OFFSET) uint32_t Svc_McaSetMbatOffsets(uint32_t mbat_offset, uint32_t smca3_offset, uint32_t s3_save_area_offset);

/**
 * @brief PSP Fw to do Mbat Table Programming into the  S3 Save Area
 * @details
 *
 * @param pmbatInfo - Pointer to MBAT Table
 *
 * @return Values  - BL_OK - The command is completed successfully
 *                   specific error BL_RETCODE for error condition
 *
 */
__svc(SVC_MCA_WRITE_MBAT_IN_S3_AREA) uint32_t Svc_McaWriteMbatInS3Area(MCA_MBAT_INFO *pmbatInfo);

/**
 * @brief  PSP Fw to Send Command to MPIO Firmware.
 * @details
 *
 * @param command           - Command to be sent to MPIO FW
 * @param arg1              - Arguments for the command (if any)
 * @param arg2              - Arguments for the command (if any)
 *
 * @param p_mpio_resp       - Response data from MPIO FW for given command.
 *
 * @return Values    :   BL_OK - The command is completed successfully
 *                      Errorcodes returned from MPIO FW
 *
 */
__svc(SVC_SEND_CMD_TO_MPIO) uint32_t Svc_SendCmdToMpio(uint32_t command, MPIO_RESP *p_mpio_resp,
                                                       uint32_t arg1, uint32_t arg2);

/**
 * @brief  Used to defer PSP autofusing
 * @details
 *
 * @return Values    :    BL_OK or error
 */
__svc(SVC_DISABLE_PSB_AUTOFUSE) uint32_t Svc_Disable_PSB_Autofuse(void);

/**
 * @brief Svc Call to decompress binary using zlib.
 * @details User application can call into this API to decompress the input data image.
 *                   to memory (mapped to AXI).
 * @param p_zlib_ops_param  - Pointer to ZLIB_OPS_PARAM.
 * @return Values    :  BL_OK - The command is completed successfully (or)
 *                      Errorcodes
 */
__svc(SVC_DECOMPRESS_ZLIB_BINARY) BL_RETCODE Svc_decompress_zlib_image(ZLIB_OPS_PARAM *p_zlib_ops_param);

/**
 * @brief               Get config/properties from BL
 *                      All unused parameters must be set to 0
 * @details             Get config/properties from BL
 *                      All unused parameters must be set to 0
 * @param            :  config_id - ID to select which config to get
 *                      p_data    - output buffer
 *                      datasize  - size of buffer
 *                      arg      - Data parameter (config_id specific)
 *
 * @return Values    :  BL_OK or error code
 */
__svc(SVC_GET_CONFIG) BL_RETCODE Svc_GetConfig(uint32_t config_id, void* p_data, uint32_t data_size, uint32_t arg);

/**
 * @brief Unload FW Binary from memory
 *
 * @param soc_fw_id - Sub Type to be unloaded from memory
 * @param pDest     - Memory address from where to unload FW Binary
 *
 * @return value: BL_OK or error code
 */
__svc(SVC_UNLOAD_BINARY) uint32_t Svc_UnloadBinary(uint32_t soc_fw_id, void *pDest);

/**
 * @brief     : set_config service call with configid.
 *
 * @details   : Service call can only have 4 parameters passed in registers r0-r3.
 *              r0 will be having the config id and r1 to r3 will be having the parametets need to be set.
 *
 * @params    : uint32_t configid will have the config id for set config. It helps in identifying the type/mode of setconfig.
 *              uint32_t arg0 address/value for set config.
 *              uint32_t arg1 address/value for set config.
 *              uint32_t arg2 address/value for set config.
 *
 * @return    : status of the operation, BL_OK or error code.
 */
__svc(SVC_SET_CONFIG) BL_RETCODE Svc_set_config(uint32_t configid, uintptr_t arg0, uintptr_t arg1, uintptr_t arg2);

__svc(SVC_SET_CONFIG) BL_RETCODE Svc_SetConfig(uint32_t configid, uint32_t arg0, uint32_t arg1, uint32_t arg2);

/**
 * @brief Generate delay in microsecond as required
 *
 * @param delay - Delay required (in microsecond)
 *
 * @return value: BL_OK or error code
 */
__svc(SVC_DELAY_IN_MICRO_SECONDS) BL_RETCODE Svc_delay_in_Microsecond(uint32_t delay);

#endif // BL_SYSCALL_H
