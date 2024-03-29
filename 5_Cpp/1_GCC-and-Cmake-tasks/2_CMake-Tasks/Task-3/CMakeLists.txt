cmake_minimum_required(VERSION 3.0)
project(cmake-docker)

find_program(DOCKER_CMD docker REQUIRED)

add_executable(hello-world main.cpp)

set(IMAGE_NAME "cmake-docker-example")
set(DOCKERFILE ${CMAKE_CURRENT_LIST_DIR}/Dockerfile)
set(_IMAGE_HASH ${CMAKE_CURRENT_BINARY_DIR}/${IMAGE_NAME}.hash)
set(_BUILD_CONTEXT context)
set(DOCKERHUB_REPO "nabeelali1207/vcognetics")

add_custom_command(
	OUTPUT ${_IMAGE_HASH}
	COMMENT "Building docker image \"${IMAGE_NAME}\""

	COMMAND ${CMAKE_COMMAND} -E remove_directory ${_BUILD_CONTEXT}
	COMMAND ${CMAKE_COMMAND} -E make_directory ${_BUILD_CONTEXT}
	COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:hello-world> ${_BUILD_CONTEXT}

	COMMAND ${DOCKER_CMD} build --tag ${IMAGE_NAME} --file ${DOCKERFILE} ${_BUILD_CONTEXT}

	COMMAND ${DOCKER_CMD} tag ${IMAGE_NAME} ${DOCKERHUB_REPO}:${IMAGE_NAME}
	COMMAND ${DOCKER_CMD} push ${DOCKERHUB_REPO}:${IMAGE_NAME}

	# COMMAND ${DOCKER_CMD} images --no-trunc ${IMAGE_NAME} > ${_IMAGE_HASH}
	DEPENDS ${DOCKERFILE} $<TARGET_FILE:hello-world>
	VERBATIM
)

add_custom_target(docker_image ALL DEPENDS ${_IMAGE_HASH})
