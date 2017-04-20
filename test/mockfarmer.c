#include <nettle/aes.h>
#include <nettle/ctr.h>
#include <nettle/ctr.h>

#include "storjtests.h"
#include "../src/rs.h"

static int e_count = 0;
static int i_count = 0;

static void farmer_request_completed(void *cls,
                                     struct MHD_Connection *connection,
                                     void **con_cls,
                                     enum MHD_RequestTerminationCode toe)
{
    *con_cls = NULL;
}

int mock_farmer_shard_server(void *cls,
                             struct MHD_Connection *connection,
                             const char *url,
                             const char *method,
                             const char *version,
                             const char *upload_data,
                             size_t *upload_data_size,
                             void **con_cls)
{
    const char *encoding = MHD_lookup_connection_value(connection,
                                                       MHD_HEADER_KIND,
                                                       MHD_HTTP_HEADER_CONTENT_TYPE);

    if (NULL == *con_cls) {

        *con_cls = (void *)connection;

        return MHD_YES;
    }

    if (0 == strcmp(method, "POST")) {

        if (*upload_data_size != 0) {
            // TODO check upload_data
            *upload_data_size = 0;
            return MHD_YES;
        }

        int ret;
        struct MHD_Response *response;
        int status_code = MHD_HTTP_NOT_FOUND;

        if (0 == strcmp(url, "/")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/1807dfe06c4507d2e0efce6636bf83a90877f501")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/23d264bcb8b014fbfcb5eabcbf29b62abb715a05")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/27c85db367ad53668a37f23e2d42683f5d33ed4f")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/4c35600c8929aabd34aaf9920fa776c1771f05f4")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/4fd785171d477f7755d5814d73bb844cf476ffb5")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/677506f70dc0d7ca77fdf19be5ab946cfdd303ab")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/6e82ccdfe28275c69ca5d97d9a345ba3d4df9105")) {
            if (i_count == 0) {
                i_count += 1;
            } else {
                status_code = MHD_HTTP_OK;
            }
        } else if (0 == strcmp(url, "/shards/7cf8773b53bd8afd1a7db8d52ac1c282dec27e79")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/c000c0e05a0bf3858f6ec49ab1d126a99aab1657")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/c11ad9e7d02fffeda0a557f003db35c3b58a7df5")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/c2dac1efe228e733f6e15a10ea3ed8258e9bd9b5")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/d328b40d9acc5a728f25168808ff8a4e8a055560")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/e14d9c962ba90ad80d0ce7d71a3fd67919ace018")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/e9a75f154ace98eea5792f2c539e200a38bf8662")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/dc5cb536f6feb255e7ac1233d825f0af2025ba5b")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/817de8fcdd64fb2adcb5f86bbdc2993879bf7c14")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/9d5e980402a69e711b6176c268bbc059d7b5fb1f")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/ec4a0f16ab581872ead75f6c6a681eb3c7861355")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/7114c67d5d18884c51e5f2efd97803f95f7ddc18")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/9354285b6750e5dff3fb6024f12826e8ab60007c")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/eb342afde185b4f14477e9df81f85830cdd2cf12")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/5dc5687381a7a09cdc98fe97cfcb1402ce8a1157")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/a16fdcfe8b8acd2d2ba8a6889aaf74f1b13004bb")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/db4af3d07dc90b0125cf465de4be1a10a478f9e4")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/bf1e4713257129d525f1381d4104c217c13cb42f")) {
            status_code = MHD_HTTP_OK;

        // PARITY SHARDS
        } else if (0 == strcmp(url, "/shards/6828f2fd1e902071d0f658e2e43cf741cd94cfc8")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/64c8fbfb07b962515993d6ad63a7ab829d283d76")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/fa417f2211e47336dfef0c51edf6e4824c1703ba")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/47b853389c1a9e7e323d20c325c3dae1a84304ba")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/acc6f8131343be6198896cda4ad046e2975390ed")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/148d79e0158dc2cf44d434db1f33c3d35cde3997")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/8460c63068b78ac94babdbeec4bf6439f93079ab")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/413d72de547fc4fe942e75570749e61105aadece")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/7f395507e58e6251f724e166ce6b18ad297a1052")) {
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/3b2432f6078b181b64a5d3f7ae21e3bcaca746c1")) {
            status_code = MHD_HTTP_OK;
        } else {
            printf("url: %s\n", url);
        }

        char *page = "";
        response = MHD_create_response_from_buffer(strlen(page),
                                                   (void *) page,
                                                   MHD_RESPMEM_PERSISTENT);
        if (!response) {
            return MHD_NO;
        }

        ret = MHD_queue_response(connection, status_code, response);
        MHD_destroy_response(response);

        return ret;
    }

    if (0 == strcmp(method, "GET")) {

        struct MHD_Response *response;

        int status_code = MHD_HTTP_NOT_FOUND;

        int ret;

        int shard_bytes = 16777216;
        int shard_bytes_sent = 16777216;
        char *page = NULL;

        struct aes256_ctx *ctx = malloc(sizeof(struct aes256_ctx));

        // mnemonic: abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon abandon about
        // bucket_id: 368be0816766b28fd5f43af5
        // file_id: 998960317b6725a3f8080c2b
        uint8_t encrypt_key[32] = {215,99,0,133,172,219,64,35,54,53,171,23,146,160,
                                   81,126,137,21,253,171,48,217,184,188,8,137,3,
                                   4,83,50,30,251};
        uint8_t ctr[16] = {70,219,247,135,162,7,93,193,44,123,188,234,203,115,129,82};
        aes256_set_encrypt_key(ctx, encrypt_key);

        int total_data_shards = 14;
        int total_parity_shards = 4;
        int total_shards = total_data_shards + total_parity_shards;
        int total_size = shard_bytes * total_shards;

        char *data = calloc(total_size, sizeof(char));
        char *bytes = "abcdefghijklmn";
        for (int i = 0; i < strlen(bytes); i++) {
            memset(data + (i * shard_bytes), bytes[i], shard_bytes);
        }

        ctr_crypt(ctx, (nettle_cipher_func *)aes256_encrypt,
                  AES_BLOCK_SIZE, ctr,
                  total_size, (uint8_t *)data, (uint8_t *)data);

        reed_solomon* rs = NULL;
        uint8_t **data_blocks = NULL;
        uint8_t **fec_blocks = NULL;
        fec_init();

        data_blocks = (uint8_t**)malloc(total_data_shards * sizeof(uint8_t *));
        if (!data_blocks) {
            fprintf(stderr, "memory error: unable to malloc");
            exit(1);
        }

        for (int i = 0; i < total_data_shards; i++) {
            data_blocks[i] = data + i * shard_bytes;
        }

        fec_blocks = (uint8_t**)malloc(total_parity_shards * sizeof(uint8_t *));
        if (!fec_blocks) {
            fprintf(stderr, "memory error: unable to malloc");
            exit(1);
        }

        for (int i = 0; i < total_parity_shards; i++) {
            fec_blocks[i] = data + (total_data_shards + i) * shard_bytes;
        }

        rs = reed_solomon_new(total_data_shards, total_parity_shards);
        reed_solomon_encode2(rs, data_blocks, fec_blocks, total_shards, shard_bytes, total_size);
        reed_solomon_release(rs);

        if (0 == strcmp(url, "/shards/269e72f24703be80bbb10499c91dc9b2022c4dc3")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 0, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/17416a592487d7b1b74c100448c8296122d8aff8")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 1, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/83cf5eaf2311a1ae9699772d9bafbb3e369a41cc")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 2, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/214ed86cb1287fe0fd18c174eecbf84341bf2655")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 3, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/1ea408fad0213a16f53421e9b72aeb0e12b93a4a")) {
            if (e_count == 0) {
                // mock a flaky farmer w/ truncated bytes
                shard_bytes_sent = shard_bytes_sent / 2;
                page = calloc(shard_bytes_sent + 1, sizeof(char));
                memset(page, 'e', shard_bytes_sent);
            } else {
                page = calloc(shard_bytes + 1, sizeof(char));
                memcpy(page, data + shard_bytes * 4, shard_bytes);
            }
            status_code = MHD_HTTP_OK;
            e_count += 1;
        } else if (0 == strcmp(url, "/shards/0219bb523832c09c77069c74804e5b0476cea7cf")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 5, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/ebcbe78dd209a03d3ce29f2e5460304de2060031")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 6, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/5ecd6cc2964a344b42406d3688e13927a51937aa")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 7, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/88c5e8885160c449b1dbb00ccf317067200b39a0")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 8, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/76b1a97498e026c47c924374b5b1148543d5c0ab")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 9, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/48e02627e37433c89fa034d3ee2df644ac7ac7a0")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 10, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/e4617532be728d48a8155ecfb200d50f00a01a23")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 11, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/973701b43290e3bef7007db0cb75744f9556ae3b")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 12, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/a0ec63ad4069fa51a53871c7a282e184371b842b")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 13, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/424cdf090604317570da38ef7d5b41abea0952df")) {
            // this is parity shard #2, parity shard #1 is missing
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 15, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/a292c0de26b2a9086473905abb938c7a1c45a9e9")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 16, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else if (0 == strcmp(url, "/shards/aca155b4deeac64f2be748e3c434e1f5e9719ef3")) {
            page = calloc(shard_bytes + 1, sizeof(char));
            memcpy(page, data + shard_bytes * 17, shard_bytes);
            status_code = MHD_HTTP_OK;
        } else {
            printf("url: %s\n", url);
        }

        char *sent_page = NULL;

        if (page) {
            sent_page = malloc(shard_bytes_sent + 1);
            memcpy(sent_page, page, shard_bytes_sent);
        } else {
            shard_bytes_sent = 9;
            sent_page = calloc(shard_bytes_sent + 1, sizeof(char));
            strcat(sent_page, "Not Found");
        }

        free(data_blocks);
        free(fec_blocks);
        free(data);
        free(page);
        free(ctx);

        response = MHD_create_response_from_buffer(shard_bytes_sent,
                                                   (void *) sent_page,
                                                   MHD_RESPMEM_MUST_FREE);

        ret = MHD_queue_response(connection, status_code, response);
        if (ret == MHD_NO) {
            fprintf(stderr, "MHD_queue_response ERROR: Bad args were passed " \
                    "(e.g. null value), or another error occurred" \
                    "(e.g. reply was already sent)\n");
        }

        MHD_destroy_response(response);

        return ret;
    }

    return MHD_NO;
}

struct MHD_Daemon *start_farmer_server()
{
    return MHD_start_daemon(MHD_USE_SELECT_INTERNALLY,
                            8092,
                            NULL,
                            NULL,
                            &mock_farmer_shard_server,
                            NULL,
                            MHD_OPTION_NOTIFY_COMPLETED,
                            &farmer_request_completed,
                            NULL,
                            MHD_OPTION_END);
}
