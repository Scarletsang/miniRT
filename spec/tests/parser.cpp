/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 14:45:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_test.hpp"

#include <iostream>

void	ModuleTest::SetUp()
{
	
}

void	ModuleTest::TearDown()
{
	
}

TEST_F(ModuleTest, float_number)
{
  t_ft_str    string = ft_str_from_cstring("12.908672372472342,0.5,0.5");
  t_mrt_range range = mrt_range(0, 1);

  struct s_ft_parser_atom atom = ft_parser_float(\
    ft_parser_atom(ft_tobject_empty(), string), ft_tobject_ptr(&range));
  EXPECT_FLOAT_EQ(atom.payload.as_float, 12.908672372472342f);
  EXPECT_EQ(atom.is_valid, true);
}

TEST_F(ModuleTest, float_number_end)
{
  t_ft_str    string = ft_str_from_cstring("70");
  t_mrt_range range = mrt_range(0, 70);

  struct s_ft_parser_atom atom = ft_parser_float(\
    ft_parser_atom(ft_tobject_empty(), string), ft_tobject_ptr(&range));
  EXPECT_FLOAT_EQ(atom.payload.as_float, 70.0f);
  EXPECT_EQ(atom.is_valid, true);
}

TEST_F(ModuleTest, float_number_false)
{
  t_ft_str    string = ft_str_from_cstring("k12.908672372472342,0.5,0.5");
  t_mrt_range range = mrt_range(0, 1);

  struct s_ft_parser_atom atom = ft_parser_float(\
    ft_parser_atom(ft_tobject_empty(), string), ft_tobject_ptr(&range));
  EXPECT_EQ(atom.is_valid, false);
}

TEST_F(ModuleTest, uint_number)
{
  t_ft_str    string = ft_str_from_cstring("123.56");
  t_mrt_range range = mrt_range(0, 1);

  struct s_ft_parser_atom atom = ft_parser_uint(\
    ft_parser_atom(ft_tobject_empty(), string), ft_tobject_ptr(&range));
  EXPECT_EQ(atom.payload.as_uint, 123u);
  EXPECT_EQ(atom.is_valid, true);
}

TEST_F(ModuleTest, vec3)
{
  t_mrt_vec3                vec3;
  t_ft_str    string = ft_str_from_cstring("0.5,0.534,0.5");
  t_mrt_range range = mrt_range(0.0, 1.0);

  struct s_ft_parser_atom atom = mrt_parser_vec3_float(\
    ft_parser_atom(ft_tobject_ptr(&vec3), string), ft_tobject_ptr(&range));
  EXPECT_FLOAT_EQ(static_cast<t_mrt_vec3 *>(atom.payload.as_ptr)->x, 0.5);
  EXPECT_FLOAT_EQ(static_cast<t_mrt_vec3 *>(atom.payload.as_ptr)->y, 0.534);
  EXPECT_FLOAT_EQ(static_cast<t_mrt_vec3 *>(atom.payload.as_ptr)->z, 0.5);
  EXPECT_EQ(atom.is_valid, true);
}

TEST_F(ModuleTest, vec3_negative)
{
  t_mrt_vec3                vec3;
  t_ft_str    string = ft_str_from_cstring("-0.5,0.534,0.5");
  t_mrt_range range = mrt_range(-1.0, 1.0);

  struct s_ft_parser_atom atom = mrt_parser_vec3_float(\
    ft_parser_atom(ft_tobject_ptr(&vec3), string), ft_tobject_ptr(&range));
  EXPECT_FLOAT_EQ(static_cast<t_mrt_vec3 *>(atom.payload.as_ptr)->x, -0.5);
  EXPECT_FLOAT_EQ(static_cast<t_mrt_vec3 *>(atom.payload.as_ptr)->y, 0.534);
  EXPECT_FLOAT_EQ(static_cast<t_mrt_vec3 *>(atom.payload.as_ptr)->z, 0.5);
  EXPECT_EQ(atom.is_valid, true);
}

TEST_F(ModuleTest, vec3_no_limit)
{
  t_mrt_vec3                vec3;
  t_ft_str    string = ft_str_from_cstring("0.5,0.534,0.5");

  struct s_ft_parser_atom atom = mrt_parser_vec3_float(\
    ft_parser_atom(ft_tobject_ptr(&vec3), string), ft_tobject_ptr(NULL));
  EXPECT_FLOAT_EQ(static_cast<t_mrt_vec3 *>(atom.payload.as_ptr)->x, 0.5);
  EXPECT_FLOAT_EQ(static_cast<t_mrt_vec3 *>(atom.payload.as_ptr)->y, 0.534);
  EXPECT_FLOAT_EQ(static_cast<t_mrt_vec3 *>(atom.payload.as_ptr)->z, 0.5);
  EXPECT_EQ(atom.is_valid, true);
}

TEST_F(ModuleTest, vec3_uint)
{
  t_mrt_vec3                vec3;
  t_ft_str    string = ft_str_from_cstring("0,5,0");
  t_mrt_range range = mrt_range(0.0, 5.0);

  struct s_ft_parser_atom atom = mrt_parser_vec3_uint(\
    ft_parser_atom(ft_tobject_ptr(&vec3), string), ft_tobject_ptr(&range));
  EXPECT_FLOAT_EQ(static_cast<t_mrt_vec3 *>(atom.payload.as_ptr)->x, 0.);
  EXPECT_FLOAT_EQ(static_cast<t_mrt_vec3 *>(atom.payload.as_ptr)->y, 5.);
  EXPECT_FLOAT_EQ(static_cast<t_mrt_vec3 *>(atom.payload.as_ptr)->z, 0.);
  EXPECT_EQ(atom.is_valid, true);
  EXPECT_EQ(atom.string.content, nullptr);
  EXPECT_EQ(atom.string.size, static_cast<size_t>(0));
}

TEST_F(ModuleTest, parse_camera)
{
  struct s_mrt_scene        scene;
  struct s_mrt_scene_entry  *camera;
  t_ft_str                  string = ft_str_from_cstring("C -50.0,0,20 0,0,1   70");

  mrt_scene_init(&scene);
  struct s_ft_parser_atom atom = mrt_scene_parser_camera(\
    ft_parser_atom(ft_tobject_ptr(&scene), string), ft_tobject_empty());
  ASSERT_EQ(atom.is_valid, true);
  camera = static_cast<struct s_mrt_scene_entry *>(ft_vector_get(&scene.entries, 0));
  EXPECT_FLOAT_EQ(camera->object.camera->origin.x, -50.0);
  EXPECT_FLOAT_EQ(camera->object.camera->origin.y, 0.0);
  EXPECT_FLOAT_EQ(camera->object.camera->origin.z, 20.0);
  EXPECT_FLOAT_EQ(camera->object.camera->orientation.x, 0.0);
  EXPECT_FLOAT_EQ(camera->object.camera->orientation.y, 0.0);
  EXPECT_FLOAT_EQ(camera->object.camera->orientation.z, 1.0);
  EXPECT_FLOAT_EQ(camera->object.camera->fov, 70.0);
  mrt_scene_free(&scene);
}
