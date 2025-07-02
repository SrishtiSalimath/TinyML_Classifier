/**
  ******************************************************************************
  * @file    network_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-07-02T14:42:22+0530
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "network_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_network_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_network_weights_array_u64[321] = {
  0x3cdcf202be87a1adU, 0x3ef7dceebfc44565U, 0xbea17458be29cbc0U, 0x3ed6fb6bbf517ae0U,
  0xbe68b589be72a2d5U, 0x3eaf5ba93ee295fcU, 0x3eb24aaa3e09fb27U, 0x3e33e8703f8d0de4U,
  0xbced0340be5a97a8U, 0xbc9e73cebf932c89U, 0xbe972242bed8fc43U, 0xbeb9ad74bd32b818U,
  0x3e82cf713d51c03aU, 0x3d78983fbce7b0d9U, 0xbf5f911d3e008e3eU, 0xbe095c00beba9898U,
  0x3cd2c3a13e53033cU, 0xbf2ab03b3edac670U, 0xbe9fc198bebbd3bdU, 0xbed3325abd8dcaf0U,
  0xbd707988bcb67cf0U, 0xbde091d0beb90ac6U, 0x3d928d913d5af3a7U, 0x3e9603b13e6e2477U,
  0x3d55b7d3bf3da402U, 0x3e8b650c3c9dad93U, 0x3bb31547bec07870U, 0xbe2a29c3bc19850eU,
  0xb9bba543bd8ba4edU, 0xbe7f37613d540488U, 0xbd4cea29bf2114daU, 0x3e57c2d73dea9049U,
  0x3da44ee6bcd61de9U, 0xbd6dcb2700000000U, 0x3e0fc75600000000U, 0xbeb40eb5bc9e90eaU,
  0x3e92547d00000000U, 0x3e8042ecU, 0xbd76efc63e064731U, 0x3eaea805U,
  0x3e8bc9adbd83381cU, 0x0U, 0x0U, 0xbbb4ed54bdc17affU,
  0x3ce6a0e43e1c7794U, 0x3e94959b3db4f5a1U, 0xbc0cdd8aU, 0xbda6bff93e354443U,
  0x3fbb6c29bdd43161U, 0x3e961eb9beb4470fU, 0xbea864ef3e95182dU, 0x404d4fb33d0e118dU,
  0x3fc2d024bd6ae6f0U, 0xbd58e1203f5b2e40U, 0x3e7636a5be3343b2U, 0xbe68fb713fc15e3eU,
  0x3f4c275e3c8c5b3eU, 0x3e8ec2c5be38e248U, 0x3e3147aa3c342800U, 0x3e3697e7be5df1dbU,
  0x3ea40e793f09673aU, 0xbe78a9253efbde1bU, 0xbe251b43be8888fcU, 0xbd467bef3f353535U,
  0x3f025ff3be0e4fe2U, 0x3e8b4ba4be6c366cU, 0xbe3d3cf5be859732U, 0x3fe625ebbdb1f6edU,
  0x3f9ca63cbca08310U, 0xbdbb036c3ecabf3aU, 0xbd1c7dda3bb7fb5eU, 0xbe45b7473f91c2a3U,
  0x3f321e913e833a8dU, 0x3e9ca32d3e8c932bU, 0x3e6924963c139620U, 0x3e6c58773e6896a9U,
  0x3ead5a9b3eea0748U, 0xbe8a482b3eb4ff1eU, 0xbe9767d63e990958U, 0x3e83f6a13e13d1aaU,
  0xbd71272cbe196850U, 0x3d8bb7a4be874282U, 0xbe66f601be7a225aU, 0x3e53ef493e9b0839U,
  0x3e90e06bbe0fca0eU, 0x3cc4f3003e84999bU, 0x3e4e9532be40336fU, 0x3eadd36d3cc7889eU,
  0xbeb5b2a63dccc9f1U, 0xbe95bb44be76cbdcU, 0xbe34a48abd887854U, 0xbe7a1c54bd9b2733U,
  0x3e376bf1bdfa5710U, 0x3e464329be49ad7aU, 0x3c59bce0bc382d9aU, 0xbdb33063be6fcb0fU,
  0xbeb2d9a13e99185dU, 0x3e61a8febdaa5098U, 0x3c37360bbe42e24bU, 0x3e85342abec53c5bU,
  0xbc2eff203d69ff88U, 0xbe2feda4bce9a16bU, 0xbe6fe924be11913aU, 0x3e4463063d80b582U,
  0x3e8f706b3e5b6e54U, 0x3e30f696be828811U, 0xbe954d19bb067d00U, 0xbe011d483e1d4415U,
  0x3e94f0b8be38cb82U, 0xbebcea83be2d8510U, 0xbe9202f83eb262ebU, 0xbd635daabe1b73aaU,
  0x3e1812c43b8c2fc9U, 0x3e306202bd903578U, 0xbda3cdf33e0a0f8aU, 0x3e997d49bd8ba404U,
  0x3d4deb043e53da2eU, 0xbd4fe5b83e71b4c0U, 0xbe473c07bcdeb56aU, 0x3ea5f3133d518c2dU,
  0x3d3fc1963da7661fU, 0x3e43dbc63d319ca8U, 0x3e0ec19abeb396d3U, 0xbd39d6083e53b69eU,
  0xbebd22003e809a51U, 0xbe8f37873d87dc9aU, 0x3e51d666bd1376bcU, 0x3e2e1ff6bcf78cefU,
  0x3fcab215bdf0a01eU, 0x3ef52624bea90582U, 0xbed57987beaa70e5U, 0x4040c06d3dbc9477U,
  0x3fa942e63e3e708eU, 0xbeaf67c43f3097d9U, 0xbeaa4f5a3ea21a6fU, 0x3eaadb6d3fc13be0U,
  0x3f7e180cbe5d2617U, 0xbda1a85c3e6f2cfaU, 0x3dce2524be7422b2U, 0x3e21be67ba9d97ffU,
  0xbbb6f3113fb3dd60U, 0xbe88b9673eb6a2c1U, 0x3e9fa941be815907U, 0x3d527e083ef8e2d0U,
  0xbeb28fc5bd479e58U, 0xbe67ee19be61d151U, 0xbe9bdcdd3e147950U, 0x3e48c9363e75d47aU,
  0xbe7fb45e3e813207U, 0xbea8abdabd751e10U, 0x3cd69a20be777294U, 0xbe926ed6be36bb4aU,
  0xbe8d61343e909e1dU, 0xbd3805f03e627426U, 0xbd211d003e7daa2aU, 0xbdc1cf40bc5e3ee0U,
  0xbe338e673e9e6d39U, 0x3e962eb9be1a668aU, 0x3e40e38a3e7f57faU, 0x3d37ad883e21029eU,
  0x3fea57ecbe305d08U, 0x3f308a70be450ea2U, 0xbe9173193d2f3ff8U, 0x405db8d3bc351c77U,
  0x3fc3185abe4f5189U, 0xbb767a003f3ac63aU, 0xbe70ca95be82c318U, 0x3c93f8703fcc0525U,
  0x3f91d24ebdda40f9U, 0x3e49a65e3c98bea0U, 0xbe1556e03e57171eU, 0x3ea2cb2abe875339U,
  0x3e3d14373fa136ecU, 0xbf0f79873e61a0e8U, 0xbe24f64bbda30bf0U, 0x3e2104073f29e3eeU,
  0x3d8c1e883d2836ecU, 0x3e3f26643e8de177U, 0x3e0703e8beaa6e99U, 0x3db87264beb360ecU,
  0x3de72d9e3e9fe711U, 0x3eae773dbec0c00eU, 0x3e035c1bbe9d873fU, 0x3e9aa513bea864bbU,
  0xbd2dc933be1ac7b8U, 0xbe8e69d43eaca86bU, 0x3e81f6933e346662U, 0x3e616feabd6d6628U,
  0x3e080a933e52be8dU, 0x3e31b05f3d18b31cU, 0xbe08bc973db133c9U, 0x3d95eec0beeeae2bU,
  0x3f76223e3e438842U, 0x3f10229ebd7672e8U, 0x3e91fd18be4b5c51U, 0x4001b32f3dc8b6adU,
  0x3ffc82273c7dd560U, 0x3ea5140f3f60ecf7U, 0xbe27a07fbdde6005U, 0xbea0358a3f1c0903U,
  0x3f81cc973e837d03U, 0xbdce8f843ea3cd7fU, 0x3ddd8e303c918f20U, 0xbd098b1fbe24c73aU,
  0xbe3848ee3f9cefaaU, 0xbeab38633e0b523aU, 0x3e809555bda8fde4U, 0x3e9a13f03f12684eU,
  0xbe734320be51494aU, 0xbdcb0623be5d963aU, 0xbea22c783e6b43ceU, 0xbe7ed6563e138bc9U,
  0xbdda11c1be9f98acU, 0xbe4fcdb33c9a6d73U, 0x3dc659f33d518cf9U, 0x3e0315c8be166e0aU,
  0xbd79d23dbd97383eU, 0xbe9af9cebcc621d0U, 0x3d453208bdbcd80cU, 0x3dff18cebd4b7fbcU,
  0x3e28f10f3ca0a70aU, 0xbec8e9873e0c7164U, 0x3e85ec35be2256d4U, 0xbdc12316bd4c6f60U,
  0xbd04f3a73e416beeU, 0x3c9b82963e8278a7U, 0x3f3f7c703ac10200U, 0xbf0ee60b3eb6d8bfU,
  0xbf03cf63be3ab2d9U, 0x3e9151ed3eaf693dU, 0xbeadcb073f0f3cb1U, 0xbd6fcd80bd814a68U,
  0x3e1e70f9be9a0ca9U, 0x3e45f93e3ea84981U, 0x3e7b63eabe6e9415U, 0x3eeac6293d467409U,
  0x3dcd7e18bd8949dcU, 0x3f6498313d3d8b5dU, 0x3d8ed1d83ea92dd8U, 0xbc4a302bbf464469U,
  0x3f731174bdb65313U, 0x3f1562743da28288U, 0xbe51c8b2be6ea190U, 0x4009e662be93e86eU,
  0x3f34efc63e2d7d4aU, 0x3db9da903e869c1cU, 0xbdf68bf43d5135f3U, 0xbdf77bd63f6f2ed0U,
  0x3f2f10563c7db54aU, 0xbc32be40bd94ca78U, 0xbddb4baebe3b9d2bU, 0x3eb11ff6be2cfe17U,
  0x3e9f25743f365efeU, 0xbefd54bf3ee8545bU, 0x3d18b328be8d71c5U, 0xbb4379423e9ed30aU,
  0xbec13a213d9180eeU, 0x3e8975c6be81a81fU, 0xbe93f25f3e87c48dU, 0xbdfe98d5bdae9cceU,
  0x3e432988be339e61U, 0x3e4be7eebda9ba74U, 0xbe25cce4bea8ea8eU, 0x3e60f2a6be459423U,
  0x3e3b9c843d35d027U, 0xbe286ed73d0301a0U, 0x3e8d20373e06fb8eU, 0x3e784e38be009e0dU,
  0x3e5813fd3e9b9fbcU, 0xbe5a22d2bedef195U, 0xbe8120d0be91a3f6U, 0x3e7afa1dbd16295aU,
  0x3eff39f73e68540cU, 0x3eb0570bbdf61890U, 0xbebbb3e1bdf070fcU, 0x4015486a3ec8523cU,
  0x3f9ca17b3df55bf0U, 0x3bd917003f391ebcU, 0xbd49bdfebd22706fU, 0x3ca28a903f994641U,
  0x3f7158813cfd301bU, 0xbe56e76d3e8dc483U, 0xbda395bc3dffde0cU, 0x3ec7baabbe4067a0U,
  0xbe455f973f2ad1d2U, 0xbe7ca4d43e8a6b5eU, 0x3d5d87d0bdd91752U, 0xbb95c2a93e7a1f58U,
  0x3f3dc078be8a5128U, 0x3e2e1778beafc95eU, 0x3d822d883e8402f1U, 0x40051d073e07d09fU,
  0x3f9860b4bd2639b0U, 0x3de292083ea1d6b5U, 0x3ceca9633e7297d6U, 0xbea19d0f3f9b6330U,
  0x3f8169df3e9e1fdcU, 0xbe1edb423dac3a80U, 0xbd110b68be887f78U, 0x3d86566bbd6326e9U,
  0xbcc4ae2b3e83a0daU, 0xbe6f241f3e6bbcc2U, 0x3d1121c83b4eab4bU, 0xbe155bfa3e349b2bU,
  0xbd6a01353bbbb55bU, 0xbcfae798bca3188bU, 0xbd33126fbd25965eU, 0x3d11005e00000000U,
  0xbe123ad1bd84b205U, 0x3eceffbfbd3eb55bU, 0xbd0a5e333c454c2cU, 0xbe2c17f5bc4a2e55U,
  0xbef6214ebf91af70U, 0x3e02da4a3e6532deU, 0xbf70d0293e6891a0U, 0xbfa016d33f00ecc0U,
  0xc021f2693e61f80bU, 0x3f19a4073f0c9923U, 0x3e1e5215bf5507bdU, 0xbed52c47bf8fce88U,
  0x3eaa8bc8U,
};


ai_handle g_network_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_network_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

