/*****************************************************************************
*
* Copyright (C) 2008-2024 Advanced Micro Devices, Inc. All rights reserved.
*
*******************************************************************************
*/

/*! \file */

#ifndef BL_ERRORCODES_H
#define BL_ERRORCODES_H

/** @enum BL_RETCODE
 * \brief BootLoader Error Codes
 *
 * Bootloader Return Codes, Error (0x00 through 0x9F) and Progress (0xA0 through 0xFF)
 *
 *   For Posrt-80, PostCodePrefix = 0xEE000000
 *   For MP0_FW_STATUS, PostCodePrefix = 0x00000100
 */
typedef enum BL_RETCODE_T {

    BL_OK                               = 0x00, /*!< General - Success */

    BL_ERR_GENERIC                      = 0x01, /*!< Generic Error Code */
    BL_ERR_MEMORY                       = 0x02, /*!< Generic Memory Error */
    BL_ERR_BUFFER_OVERFLOW              = 0x03, /*!< Buffer Overflow */
    BL_ERR_INVALID_PARAMETER            = 0x04, /*!< Invalid Parameter(s) */
    BL_ERR_DATA_LENGTH                  = 0x05, /*!< Invalid Data Length */
    BL_ERR_DATA_ALIGNMENT               = 0x06, /*!< Data Alignment Error */
    BL_ERR_NULL_PTR                     = 0x07, /*!< Null Pointer Error */
    BL_ERR_FUNCTION_NOT_SUPPORTED       = 0x08, /*!< Unsupported Function */
    BL_ERR_INVALID_SERVICE_ID           = 0x09, /*!< Invalid Service ID */
    BL_ERR_INVALID_ADDRESS              = 0x0A, /*!< Invalid Address */
    BL_ERR_OUT_OF_RESOURCES             = 0x0B, /*!< Out of Resource Error */
    BL_ERR_TIMEOUT                      = 0x0C, /*!< Timeout */
    BL_ERR_DATA_ABORT                   = 0x0D, /*!< data abort exception */
    BL_ERR_PREFETCH_ABORT               = 0x0E, /*!< prefetch abort exception */
    BL_ERR_BOUNDARY_CHECK               = 0x0F, /*!< Out of Boundary Condition Reached */
    BL_ERR_DATA_CORRUPTION              = 0x10, /*!< Data corruption */
    BL_ERR_INVALID_COMMAND              = 0x11, /*!< Invalid command */
    BL_ERR_INCORRECT_PACKAGE_TYPE       = 0x12, /*!< The package type provided by BR is incorrect */
    BL_ERR_GET_FW_HEADER                = 0x13, /*!< Failed to retrieve FW header during FW validation */
    BL_ERR_KEY_SIZE                     = 0x14, /*!< Key size not supported */
    BL_ERR_AGESA0                       = 0x15, /*!< Agesa0 verification error */
    BL_ERR_SMUFW                        = 0x16, /*!< SMU FW verification error */
    BL_ERR_OEMSIGNING                   = 0x17, /*!< OEM SINGING KEY verification error */
    BL_ERR_FWVALIDATION                 = 0x18, /*!< Generic FW Validation error */
    BL_ERR_CCP_RSA                      = 0x19, /*!< RSA operation fail - bootloader */
    BL_ERR_CCP_PASSTHR                  = 0x1A, /*!< CCP Passthrough operation failed - internal status */
    BL_ERR_CCP_AES                      = 0x1B, /*!< AES operation fail */
    BL_ERR_STATE_SAVE                   = 0x1C, /*!< CCP state save failed */
    BL_ERR_STATE_RESTORE                = 0x1D, /*!< CCP state restore failed */
    BL_ERR_SHA                          = 0x1E, /*!< SHA256/384 operation fail - internal status */
    BL_ERR_ZLIB                         = 0x1F, /*!< ZLib Decompression operation fail */
    BL_ERR_HMAC_SHA                     = 0x20, /*!< HMAC-SHA256/384 operation fail - internal status */
    BL_ERR_INVALID_BOOT_SOURCE          = 0x21, /*!< Booted from boot source not recognized by PSP */
    BL_ERR_DIR_ENTRY_NOT_FOUND          = 0x22, /*!< PSP directory entry not found */
    BL_ERR_SPIROM_WRITE_FAIL            = 0x23, /*!< PSP failed to set the write enable latch */
    BL_ERR_SPIROM_BUSY_TIMEOUT          = 0x24, /*!< PSP timed out because spirom took too long */
    BL_ERR_CANNOT_FIND_BIOS_DIR         = 0x25, /*!< Cannot find BIOS directory */
    BL_ERR_SPIROM_SIZE                  = 0x26, /*!< SpiRom is not valid */
    BL_ERR_SECURITY_STATE_DIFF          = 0x27, /*!< slave die has different security state from master */
    BL_ERR_SMI_INIT_ERROR               = 0x28, /*!< SMI interface init failure */
    BL_ERR_SMI_GENERIC                  = 0x29, /*!< SMI interface generic error */
    BL_ERR_INVALID_DIE_ID               = 0x2A, /*!< invalid die ID executes MCM related function */
    BL_ERR_INVALID_MCM_CONFIG           = 0x2B, /*!< invalid MCM configuration table read from bootrom */
    BL_ERR_DETECT_BOOT_MODE             = 0x2C, /*!< Valid boot mode wasn't detected */
    BL_ERR_NVSTORAGE_INIT_FAILURE       = 0x2D, /*!< NVStorage init failure */
    BL_ERR_NVSTORAGE_GENERIC            = 0x2E, /*!< NVStorage generic error */
    BL_ERR_MCM_MORE_DATA                = 0x2F, /*!< MCM 'error' to indicate slave has more data to send */
    BL_ERR_MCM_DATA_LENGTH              = 0x30, /*!< MCM error if data size exceeds 32B */
    BL_ERR_MCM_INVALID_ID               = 0x31, /*!< Invalid client id for SVC MCM call */
    BL_ERR_MCM_INVALID_STATE            = 0x32, /*!< MCM slave status register contains bad bits */
    BL_ERR_MCM_NO_SLAVES                = 0x33, /*!< MCM call was made in a single die environment */
    BL_ERR_PSP_SECURE_MAP               = 0x34, /*!< PSP secure mapped to invalid segment (should be 0x400_0000) */
    BL_ERR_NO_PHY_CORES_PRESENT         = 0x35, /*!< No physical x86 cores were found on die */
    BL_ERR_SECURE_OS_INSUF_SRAM         = 0x36, /*!< Insufficient space for secure OS (range of free SRAM to SVC stack base) */
    BL_ERR_UNSUP_SYSHUB_TARGET_TYPE     = 0x37, /*!< SYSHUB mapping memory target type is not supported */
    BL_ERR_UNMAP_PSP_SECURE_REGION      = 0x38, /*!< Attempt to unmap permanently mapped TLB to PSP secure region */
    BL_ERR_SMNMAP_FAILED                = 0x39, /*!< Unable to map an SMN address to AXI space */
    BL_ERR_SYSHUBMAP_FAILED             = 0x3A, /*!< Unable to map a SYSHUB address to AXI space */
    BL_ERR_CORECONFIG_COUNT_MISMATCH    = 0x3B, /*!< The count of CCXs or cores provided by bootrom is not consistent */
    BL_ERR_UNCOMP_IMAGE_SIZE_MISMATCH   = 0x3C, /*!< Uncompressed image size doesn't match value in compressed header */
    BL_ERR_UNSUPPORTED_COMP_OPTION      = 0x3D, /*!< Compressed option used in case where not supported */
    BL_ERR_FUSE_INFO                    = 0x3E, /*!< Fuse info on all dies don't match */
    BL_ERR_PSP_SMU_MSG_FAIL             = 0x3F, /*!< PSP sent message to SMU; SMU reported an error */
    BL_ERR_POST_X86_RELEASE_TEST_FAIL   = 0x40, /*!< Function RunPostX86ReleaseUnitTests failed in memcmp() */
    BL_ERR_PSP_SMU_INTERFACE            = 0x41, /*!< Interface between PSP to SMU not available. */
    BL_ERR_TIMER_PARAM_OVERFLOW         = 0x42, /*!< Timer wait parameter too large */
    BL_ERR_TEST_HARNESS_MODULE          = 0x43, /*!< Test harness module reported an error */
    BL_ERR_VMG_INVALID_COMMAND          = 0x44, /*!< x86 wrote C2PMSG_0 interrupting PSP, but the command has an invalid format */
    BL_ERR_BIOS_DIR_COOKIE_MISMATCH     = 0x45, /*!< Failed to read from SPI the Bios Directory or Bios Combo Directory */
    BL_ERR_SPL_LOOKUP                   = 0x46, /*!< Failed to find FW entry in SPL Table */
    BL_ERR_COMBO_BIOS_HEADER_MISMATCH   = 0x47, /*!< Failed to read the combo bios header */
    BL_ERR_INVALID_SPL_VERSION          = 0x48, /*!< SPL version missmatch */
    BL_ERR_LOAD_VALIDATE_APOB           = 0x49, /*!< Error in Validate and Loading AGESA APOB SVC call */
    BL_ERR_WAIT_FOR_RESET_ASSERTION     = 0x4A, /*!< Correct fuse bits for DIAG_BL loading not set */
    BL_ERR_UMC_NOT_INIT_BY_AGESA        = 0x4B, /*!< The UmcProgramKeys() function was not called by AGESA */
    BL_ERR_WHITE_LISTING                = 0x4C, /*!< Unconditional Unlock based on serial numbers failure */
    BL_ERR_SYSHUBIF_REG_MISMATCH        = 0x4D, /*!< Syshub register programming mismatch during readback */
    BL_ERR_SECURE_FUSE_FAMILY_ID        = 0x4E, /*!< Family ID in MP0_SFUSE_SEC[7:3] not correct */
    BL_ERR_NOT_GLOBAL_MASTER            = 0x4F, /*!< An operation was invoked that can only be performed by the GM */
    BL_ERR_SMB_TIMEOUT_ACQR_HOST_SEMA   = 0x50, /*!< Failed to acquire host controller semaphore to claim ownership of SMB */
    BL_ERR_SMB_TIMEOUT_WAIT_HOST_IDLE   = 0x51, /*!< Timed out waiting for host to complete pending transactions */
    BL_ERR_SMB_TIMEOUT_WAIT_SLAVE_IDLE  = 0x52, /*!< Timed out waiting for slave to complete pending transactions */
    BL_ERR_SMB_HOST_BUSY                = 0x53, /*!< Unable to kill current transaction on host, to force idle */
    BL_ERR_SMB_DEVICE_ERROR             = 0x54, /*!< One of: Illegal command, Unclaimed cycle, or Host time out */
    BL_ERR_SMB_BUS_COLLISION            = 0x55, /*!< An smbus transaction collision detected, operation restarted */
    BL_ERR_SMB_TRANSACTION_FAILED       = 0x56, /*!< Transaction failed to be started or processed by host, or not completed */
    BL_ERR_SMB_UNSOLICITED_INTR_RX      = 0x57, /*!< An unsolicited smbus interrupt was received */
    BL_ERR_PSP_SMU_UNSUPPORTED_MSG      = 0x58, /*!< An attempt to send an unsupported PSP-SMU message was made */
    BL_ERR_PSP_SMU_CORRUPTED_TXFR       = 0x59, /*!< An error/data corruption detected on response from SMU for sent msg */
    BL_ERR_MCM_STEADY_UNIT_TEST_FAILED  = 0x5A, /*!< MCM Steady-state unit test failed */
    BL_ERR_S3_ENTER_FAILED              = 0x5B, /*!< S3 Enter failed */
    BL_ERR_PSP_SMU_RESERVED_NOT_SET     = 0x5C, /*!< AGESA BL did not set PSP SMU reserved addresses via SVC call */
    BL_ERR_PSP_SMU_RESERVED_INVALID     = 0x5D, /*!< Reserved PSP/SMU memory region is invalid */
    BL_ERR_UNFUSED_PART                 = 0x5E, /*!< CcxSecBisiEn not set in fuse RAM */
    BL_ERR_UNIT_TEST_UNEXPECTED_RESULT  = 0x5F, /*!< Received an unexpected result */
    BL_ERR_VMG_STORAGE_INIT_FAILED      = 0x60, /*!< VMG Storage Init failed */
    BL_ERR_MBEDTLS_USER_APP             = 0x61, /*!< failure in mbedTLS user app */
    BL_ERR_FUSE_SMN_MAPPING_FAILED      = 0x62, /*!< An error occured whilst attempting to SMN map a fuse register */
    BL_ERR_FUSE_BURN_FAILED_SOC         = 0x63, /*!< Fuse burn sequence/operation failed due to internal SOC error */
    BL_ERR_FUSE_SENSE_TIMEOUT           = 0x64, /*!< Fuse sense operation timed out */
    BL_ERR_FUSE_BURN_FAILED_TIMEOUT     = 0x65, /*!< Fuse burn sequence/operation timed out waiting for burn done */
    BL_ERR_PMU_FW_KEY                   = 0x66, /*!< The PMU FW Public key certificate loading or authentication fails */
    BL_ERR_FUSE_FW_ID_REVOKED           = 0x67, /*!< This PSP FW was revoked */
    BL_ERR_PLATFORM_ID                  = 0x68, /*!< The platform model/vendor id fuse is not matching the BIOS public key token */
    BL_ERR_BIOS_KEY_REV_ID              = 0x69, /*!< The BIOS OEM public key of the BIOS was revoked for this platform */
    BL_ERR_PSP_LV2_HEADER_NOT_MATCH     = 0x6A, /*!< PSP level 2 directory not match expected value. */
    BL_ERR_BIOS_LV2_HEADER_NOT_MATCH    = 0x6B, /*!< BIOS level 2 directory not match expected value. */
    BL_ERR_RESET_IMAGE_NOT_FOUND        = 0x6C, /*!< Reset image not found */
    BL_ERR_CCP_INIT                     = 0x6D, /*!< Generic error indicating the CCP HAL initialization failed */
    BL_ERR_NVRAM_DRAM_FAIL              = 0x6E, /*!< failure to copy NVRAM to DRAM. */
    BL_ERR_INVALID_KEY_USAGE_FLAG       = 0x6F, /*!< Invalid key usage flag */
    BL_ERR_UNEXPECTED_FUSE_SET          = 0x70, /*!< Unexpected fuse set */
    BL_ERR_RSMU_SECURITY_VIOLATION      = 0x71, /*!< RSMU signaled a security violation */
    BL_ERR_WAFL_PCS_PROGRAMMING         = 0x72, /*!< Error programming the WAFL PCS registers */
    BL_ERR_WAFL_SET_THRESHOLD           = 0x73, /*!< Error setting wafl PCS threshold value */
    BL_ERR_LOAD_OEMTRUSTLET             = 0x74, /*!< Error loading OEM trustlets */
    BL_ERR_RECOVERY_MODE_SYNC           = 0x75, /*!< Recovery mode accross all dies is not sync'd */
    BL_ERR_WAFL_UNCORRECTABLE           = 0x76, /*!< Uncorrectable WAFL error detected */
    BL_ERR_MP1_FATAL                    = 0x77, /*!< Fatal MP1 error detected */
    BL_ERR_BIOS_RTM_SIG_MISSING         = 0x78, /*!< Bootloader failed to find OEM signature */
    BL_ERR_BIOS_COPY                    = 0x79, /*!< Error copying BIOS to DRAM */
    BL_ERR_BIOS_VALIDATION              = 0x7A, /*!< Error validating BIOS image signature */
    BL_ERR_OEM_KEY_INVALID              = 0x7B, /*!< OEM Key validation failed */
    BL_ERR_PLATFORM_BINDING             = 0x7C, /*!< Platform Vendor ID and/or Model ID binding violation */
    BL_ERR_BIOS_BOOT_FROM_SPI           = 0x7D, /*!< Bootloader detects BIOS request boot from SPI-ROM, which is unsupported for PSB. */
    BL_ERR_FUSE_ALREADY_BLOWN           = 0x7E, /*!< Requested fuse is already blown, reblow will cause ASIC malfunction */
    BL_ERR_FUSE_ERROR_BLOWNFUSE         = 0x7F, /*!< Error with actual fusing operation */
    BL_ERR_FUSE_INFO_P1                 = 0x80, /*!< (Local Master PSP on P1 socket) Error reading fuse info */
    BL_ERR_PLATFORM_BINDING_P1          = 0x81, /*!< (Local Master PSP on P1 socket) Platform Vendor ID and/or Model ID binding violation */
    BL_ERR_FUSE_ALREADY_BLOWN_P1        = 0x82, /*!< (Local Master PSP on P1 socket) Requested fuse is already blown, reblow will cause ASIC malfunction */
    BL_ERR_FUSE_ERROR_BLOWNFUSE_P1      = 0x83, /*!< (Local Master PSP on P1 socket) Error with actual fusing operation */
    BL_ERR_SEV_ROLLBACK_DETECTED        = 0x84, /*!< SEV FW Rollback attempt is detected */
    BL_ERR_SEV_DOWNLOADFW_BROADCAST_FAIL= 0x85, /*!< SEV download FW command fail to broadcase and clear the IsInSRAM field on slave dies */
    BL_ERR_ERROR_INJECTION_NOT_ENABLED  = 0x86, /*!< Agesa error injection failure */
    BL_ERR_TWIX_UNCORRECTABLE           = 0x87, /*!< Uncorrectable TWIX error detected */
    BL_ERR_TWIX_PROGRAMMING             = 0x88, /*!< Error programming the TWIX PCS registers */
    BL_ERR_TWIX_SET_THRESHOLD           = 0x89, /*!< Error setting TWIX PCS threshold value */
    BL_ERR_CCP_QUEUE_FULL               = 0x8A, /*!< SW CCP queue is full, cannot add more entries */
    BL_ERR_CCP_CMD_ERROR                = 0x8B, /*!< CCP command description syntax error detected from input */
    BL_ERR_CCP_CMD_NOTSCHEDULED         = 0x8C, /*!< Return value stating that the command has not yet be scheduled */
    BL_ERR_CCP_CMD_BEINGWORKEDON        = 0x8D, /*!< The command is scheduled and being worked on */
    BL_ERR_DXIO_PHY_SRAM_FW_KEY         = 0x8E, /*!< The DXIO PHY SRAM Public key certificate loading or authentication fails */
    BL_ERR_FTPMSIZE_EXCEED_LIMIT        = 0x8F, /*!< fTPM binary size exceeds limit allocated in Private DRAM, need to increase the limit */
    BL_ERR_TWIX_LINK_NOT_TRAINED        = 0x90, /*!< The TWIX link for a particular CCD is not trained Fatal error */
    BL_ERR_MCM_SS_CHECK_FAILED          = 0x91, /*!< Security check failed (not all dies are in same security state) */
    BL_ERR_FWTYPE_MISMATCH              = 0x92, /*!< FW type mismatch between the requested FW type and the FW type embedded in the FW binary header */
    BL_ERR_SVC_CALL_ADDR_VIOLATION      = 0x93, /*!< SVC call input parameter address violation */
    BL_ERR_FCL_MISMATCH                 = 0x94, /*!< Firmware Compatibility Level mismatch */
    BL_ERR_KNOLL_BAD_STATUS             = 0x95, /*!< Bad status returned by I2CKnollCheck */
    BL_ERR_INVALID_IDEVID               = 0x96, /*!< IDEVID certificate is invalid */
    BL_ERR_I2C_KNOLL_NULL_PTR           = 0x97, /*!< Null pointer passed to I2CKnollCheck */
    BL_ERR_KNOLL_DEV_ID_INVALID         = 0x98, /*!< Invalid device-ID found during Knoll authentication */
    BL_ERR_KNOLL_KEY_DERIV              = 0x99, /*!< Error during Knoll/Prom key derivation */
    BL_ERR_CCP_NULL_PTR                 = 0x9A, /*!< Null pointer passed to Crypto function */
    BL_ERR_PSP_SMU_UNKNOWN_MSG_FAIL     = 0x9B, /*!< SMU reports Unknown command for sent message. This is non-blocking */
    BL_ERR_KNOLL_INVALID_RESPONSE       = 0x9C, /*!< Knoll returned an invalid response to a command */
    BL_ERR_KNOLL_SEND_CMD_FAILED        = 0x9D, /*!< Bootloader failed in Knoll Send Command function */
    BL_ERR_KNOLL_TEST_FAILED            = 0x9E, /*!< No Knoll device found by verifying MAC */
    BL_ERR_POSTCODE_MAX_VALUE           = 0x9F, /*!< The maximum allowable error post code */

    /*!< ********************************************************************************************/
    /*!< ************************************* BL_TRACECODE *****************************************/
    /*!< ********************************************************************************************/

    BL_SUCCESS_C_MAIN                   = 0xA0, /*!< Bootloader successfully entered C Main */
    BL_SUCCESS_P2PMBOX_INIT             = 0xA1, /*!< Master initialized C2P / slave waited for master to init C2P */
    BL_SUCCESS_DERIVE_HMAC_KEY          = 0xA2, /*!< HMAC key successfully derived */
    BL_SUCCESS_DETECT_BOOT_MODE         = 0xA3, /*!< Master got Boot Mode and sent boot mode to all slaves */
    BL_SUCCESS_SPI_INIT                 = 0xA4, /*!< SpiRom successfully initialized */
    BL_SUCCESS_COPY_BIOS_DIRECTORY      = 0xA5, /*!< BIOS Directory successfully read from SPI to SRAM */
    BL_SUCCESS_CHECK_EARLY_UNLOCK       = 0xA6, /*!< Early unlock check */
    BL_SUCCESS_DERIVE_INLINE_AES_KEY    = 0xA7, /*!< Inline Aes key successfully derived */
    BL_SUCCESS_INLINE_AES_KEY_PROGRAM   = 0xA8, /*!< Inline-AES key programming is done */
    BL_SUCCESS_INLINE_AES_KEY_WRAPPER   = 0xA9, /*!< Inline-AES key wrapper derivation is done */
    BL_SUCCESS_IP_CONFIG                = 0xAA, /*!< Bootloader successfully loaded HW IP configuration values */
    BL_SUCCESS_MBAT_PROGRAMMING         = 0xAB, /*!< Bootloader successfully programmed MBAT table */
    BL_SUCCESS_LOAD_SMU                 = 0xAC, /*!< Bootloader successfully loaded SMU FW */
    BL_SUCCESS_SET_RECOVERY_MODE        = 0xAD, /*!< Bootloader entering into Recovery Mode */
    BL_SUCCESS_USER_MODE_TEST_UAPP      = 0xAE, /*!< User mode test Uapp completed successfully */
    BL_SUCCESS_START_AGESA              = 0xAF, /*!< Bootloader loaded Agesa0 from SpiRom */
    BL_SUCCESS_FINISHED_AGESA           = 0xB0, /*!< AGESA phase has completed */
    BL_SUCCESS_POST_DRAM_TESTS          = 0xB1, /*!< RunPostDramTrainingTests() completed successfully */
    BL_SUCCESS_IDEVID_VALIDATION        = 0xB2, /*!< IDEVID validation is successful*/
    BL_SUCCESS_BYPASS_IDEVID_CHECK      = 0xB3, /*!< IDEVID validation failed, but error is bypassed on an unsecure part*/
    BL_SUCCESS_RUN_SECURITY_GASKET      = 0xB4, /*!< Validated and ran Security Gasket binary */
    BL_SUCCESS_UMC_SECURITY_INIT        = 0xB5, /*!< UMC Keys generated and programmed */
    BL_SUCCESS_STORE_WRAPPED_KEY        = 0xB6, /*!< Inline AES key wrapper stored in DRAM */
    BL_SUCCESS_VALIDATED_OEM_KEY        = 0xB7, /*!< Completed FW Validation step */
    BL_SUCCESS_VALIDATED_BIOS_RST       = 0xB8, /*!< Completed FW Validation step */
    BL_SUCCESS_LOADING_BIOS_COMPONENTS  = 0xB9, /*!< BIOS copy from SPI to DRAM complete */
    BL_SUCCESS_VALIDATED_BIOS           = 0xBA, /*!< Completed FW Validation step */
    BL_SUCCESS_BIOS_LOAD_COMPLETE       = 0xBB, /*!< BIOS load process fully complete */
    BL_SUCCESS_RELEASE_X86              = 0xBC, /*!< Bootloader successfully release x86 */
    BL_SUCCESS_NORMAL_UNLOCK            = 0xBD, /*!< Early Secure Debug completed */
    BL_SUCCESS_GET_VERSION_COMMAND      = 0xBE, /*!< GetFWVersion command received from BIOS is completed */
    BL_SUCCESS_SMI_INFO_COMMAND         = 0xBF, /*!< SMIInfo command received from BIOS is completed */
    BL_SUCCESS_ENTER_WARM_BOOT          = 0xC0, /*!< Successfully entered WarmBootResume() */
    BL_SUCCESS_COPIED_SECURE_OS_SRAM    = 0xC1, /*!< Successfully copied SecureOS image to SRAM */
    BL_SUCCESS_COPIED_TRUSTLETS_DRAM    = 0xC2, /*!< Successfully copied trustlets to PSP Secure Memory */
    BL_SUCCESS_JUMPING_TO_SECURE_OS     = 0xC3, /*!< About to jump to Secure OS (SBL about to copy and jump) */
    BL_SUCCESS_RESTORED_CCP_STATE       = 0xC4, /*!< Successfully restored CCP and UMC state on S3 resume */
    BL_SUCCESS_WARM_MB_SRAMHMAC_PASS    = 0xC5, /*!< PSP SRAM HMAC validated by Mini BL */
    BL_SUCCESS_WARM_MB_TRANSFER2OS      = 0xC6, /*!< About to jump to <t-base in Mini BL */
    BL_SUCCESS_VMG_ECDH_UNIT_TEST_START = 0xC7, /*!< VMG ECDH unit test started */
    BL_SUCCESS_VMG_ECDH_UNIT_TEST_PASS  = 0xC8, /*!< VMG ECDH unit test passed */
    BL_SUCCESS_VMG_ECC_CDH_TEST_START   = 0xC9, /*!< VMG ECC CDH primitive unit test started */
    BL_SUCCESS_VMG_ECC_CDH_TEST_PASS    = 0xCA, /*!< VMG ECC CDH primitive unit test passed */
    BL_SUCCESS_VMG_KDF_TEST_START       = 0xCB, /*!< VMG SP800-108 KDF-CTR HMAC unit test started */
    BL_SUCCESS_VMG_KDF_TEST_PASS        = 0xCC, /*!< VMG SP800-108 KDF-CTR HMAC unit test passed */
    BL_SUCCESS_VMG_LAUNCH_TEST_START    = 0xCD, /*!< VMG LAUNCH_* test started */
    BL_SUCCESS_VMG_LAUNCH_TEST_PASS     = 0xCE, /*!< VMG LAUNCH_* test passed */
    BL_SUCCESS_MP1_RESET_COMPLETE       = 0xCF, /*!< MP1 has been taken out of reset, and executing SMUFW */
    BL_SUCCESS_PSP_SMU_RESERVED_PROG    = 0xD0, /*!< PSP and SMU Reserved Addresses correct */
    BL_SUCCESS_PSP_STEADY_STATE         = 0xD1, /*!< Reached Naples steady-state WFI loop */
    BL_SUCCESS_WDT_1_COUNTER_EXPIRED    = 0xD2, /*!< SIB PIC0 WDT Stage 1 Expiry */
    BL_SUCCESS_KNOLL_NONCE_COMPLETE     = 0xD3, /*!< 32-byte RandOut successfully returned from Knoll */
    BL_SUCCESS_KNOLL_MAC_COMPLETE       = 0xD4, /*!< 32-byte MAC successfully received from Knoll. */
    BL_SUCCESS_KNOLL_VERIFIED           = 0xD5, /*!< Knoll device verified successfully */
    BL_SUCCESS_CNLI_SECURITY_INIT       = 0xD6, /*!< CNLI Keys generated and programmed */
    BL_RECOVERY_TRUSTLET_VALIDATE_FAIL  = 0xD7, /*!< Enter recovery mode due to trustlet validation fail. */
    BL_RECOVERY_OS_VALIDATE_FAIL        = 0xD8, /*!< Enter recovery mode due to OS validation fail. */
    BL_RECOVERY_OEM_PUBLIC_KEY_FAIL     = 0xD9, /*!< Enter recovery mode due to OEM public key not found. */
    BL_RECOVERY_HEADER_CORRUPTION       = 0xDA, /*!< Enter recovery mode with header corruption */
    BL_ERR_SECURE_UNLOCK_FAIL           = 0xDB, /*!< We should not treat this error as blocking */
    BL_SUCCESS_SRAM_IMAGE_ALREADY_LOADED= 0xDC, /*!< When same fw image type is already loaded in SRAM */
    BL_SUCCESS_SECURE_UNLOCK_RETURN     = 0xE0, /*!< Unlock return */
    BL_SUCCESS_TRIGGER_SYSTEM_RESET     = 0xE2, /*!< Token exipration reset triggered */
    BL_SUCCESS_VALIDATED_DXIO_PHY_FW_KEY= 0xE3, /*!< Completed DXIO PHY SRAM FW key Validation step */
    BL_SUCCESS_MP1_SRAM_LOAD            = 0xE4, /*!< MP1 firmware load to SRAM success */
    BL_SUCCESS_MP1_SRAM_READ            = 0xE5, /*!< Bootloader read the MP1 SRAM successfully */
    BL_SUCCESS_MP1_RESET_DONE           = 0xE6, /*!< Bootloader successfully reset MP1 */
    BL_SUCCESS_DF_INIT                  = 0xE7, /*!< DF init successfully done (in absence of AGESA) */
    BL_SUCCESS_UMC_INIT                 = 0xE8, /*!< UMC init successfully done (in absence of AGESA) */
    BL_SUCCESS_LX6_ROM_READY            = 0xE9, /*!< LX6 Boot ROM code ready */
    BL_SUCCESS_LX6_ASSERT_RESET         = 0xEA, /*!< Bootloader successfully asserted LX6 reset */
    BL_SUCCESS_LX6_SRAM_LOAD            = 0xEB, /*!< LX6 load to SRAM success */
    BL_SUCCESS_LX6_RESET_VECTOR_SEL     = 0xEC, /*!< Bootloader successfully set LX6 reset vector to SRAM */
    BL_SUCCESS_LX6_DEASSERT_RESET       = 0xED, /*!< Bootloader successfully de-asserted LX6 reset */
    BL_SUCCESS_LX6_FW_READY             = 0xEE, /*!< LX6 firmware is running and ready */
    BL_SUCCESS_S3_IMAGE_LOAD_DONE       = 0xEF, /*!< Loading of S3 image done successfully */
    BL_SUCCESS_2K4K_KEY_VERIFY          = 0xF0, /*!< Bootloader successfully verify signed image using 4K/2K key */
    BL_SUCCESS_MULTI_SOCKET_BOOT        = 0xF1, /*!< Bootloader identified as running multi-socket boot */
    BL_SUCCESS_SECURITY_POLICY_CHECK    = 0xF2, /*!< Security Policy check successful (only in secure boot) */
    BL_SUCCESS_SS3                      = 0xF3, /*!< Bootloader successfully loaded SS3 */
    BL_SUCCESS_FTPM                     = 0xF4, /*!< Bootloader successfully load fTPM Driver */
    BL_SUCCESS_SYS_DRV                  = 0xF5, /*!< Bootloader successfully loaded sys_drv */
    BL_SUCCESS_SOS                      = 0xF6, /*!< Bootloader successfully loaded secure OS */
    BL_SUCCESS_CONTROL_TO_SOS           = 0xF7, /*!< Bootloader about to transfer control to secureOS */
    BL_SUCCESS_BOOT_DONE                = 0xFF, /*!< Bootloader sequence finished */
    BL_SUCCESS_MAX_VAL                  = BL_SUCCESS_BOOT_DONE, /*!< This is the Max Value for PostCode */
    BL_FORCE_32_BIT_ENUM                = 0x7FFFFFFF /*!< [UNUSED] Added to force this enum to 32-bits */
} BL_RETCODE;

/**
 * Mask for Bootloader return code.
 */
#define BL_RET_STATUS_MASK   0xFFu /*!< Use to ensure bitwise operations with BL_RETCODE are clean */

#endif // BL_ERRORCODES_H
